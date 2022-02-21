//sorting array of 0s 1s and 2s

// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
        
//         int j=0;
//         int k=nums.size()-1;
        
//         // because till k vector is sorted because of swapping
//         for(int i=0;i<=k;i++){
//             if(nums[i]==0)swap(nums[i],nums[j++]);
//             if(nums[i]==2)swap(nums[i--],nums[k--]);
            
//         }
//     }
// };

//another solution can be counting the numbers of occurences of each number and then putting again in the array

class Solution{
    public: 
        void sortColors(vector<int>& nums){
            int n0=0,n1=0,n2=0;
            
            for(auto &num:nums){
                if(num==0)n0++;
                else if(num==1)n1++;
                else if(num==2)n2++;
            }
            nums.clear();
            for(int i=0;i<n0;i++)nums.push_back(0);
            for(int i=0;i<n1;i++)nums.push_back(1);
            for(int i=0;i<n2;i++)nums.push_back(2);
        }
};
