class Solution{
    public:
        int divide(vector<int>& nums,int start,int end){
            if(start<end){
                int mid=(end-start)/2 + start;
                int lss=divide(nums,start,mid);
                int rss=divide(nums,mid+1,end);
                
                //lss ->leftsubarray
                //rss ->rightsubarray
                //css ->crosssubarray
                
                int left=INT_MIN,right=INT_MIN,css=0;
                int curr=0;

                for(int i=mid;i>=start;i--){
                    curr+=nums[i];
                    left=max(left,curr);
                }
                curr=0;
                for(int i=mid+1;i<=end;i++){
                    curr+=nums[i];
                    right=max(right,curr);
                }
                css=left+right;
                
                
                return max(css,max(lss,rss));
            }
            else return nums[end];//to handle case of single int in num
        }

        int maxSubArray(vector<int>& nums){
            int n=nums.size();
            return divide(nums,0,n-1);   
        }
        
};

//Kadane's algorithm

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int Max=nums[0];
        int currMax=0;
            
        for(int i=0;i<nums.size();i++){
            currMax+= nums[i];
            if(currMax>Max) Max=currMax;
            if(currMax<0) currMax=0;
        }
        return Max;
    }
};
