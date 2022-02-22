class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        vector<int>subAns;
        int dp[numRows][numRows];
        memset( dp, 0, sizeof(dp));
        
        for(int i=0,j=0;i<numRows;i++){
            dp[i][j]=1;
        }
        for(int row=1;row<numRows;row++){
            for(int col=1;col<=row;col++){
                dp[row][col]=dp[row-1][col-1]+dp[row-1][col];
            }
        }
        for(int i=0;i<numRows;i++){
            for(int j=0;j<numRows;j++){
                if(dp[i][j]==0)break;
                subAns.push_back(dp[i][j]);
            }
            ans.push_back(subAns);
            subAns.clear();
        }
        return ans;
    }
};

//further optimisation
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        vector<int>subAns;
        vector<int>dp1(numRows,0);
        vector<int>dp2(numRows,0);
        dp1[0]=1;dp2[0]=1;
        
        
        for(int i=1;i<=numRows;i++){
            subAns.clear();
            subAns.push_back(1);
            for(int j=1;j<i;j++){
                dp2[j]=dp1[j-1]+dp1[j];
                subAns.push_back(dp2[j]);
            }
            dp1=dp2;
            ans.push_back(subAns);
        }
        return ans;
    }
};