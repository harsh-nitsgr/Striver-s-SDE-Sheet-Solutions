class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
     
        int j=m-1,k=n-1;
        int s=nums1.size()-1;
        while(k>=0){
            nums1[s--] = j>=0 && (nums1[j]>nums2[k])? nums1[j--]:nums2[k--];
        }
        
    }
};
