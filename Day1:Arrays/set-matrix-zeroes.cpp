class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        unordered_set<int>set1;
        unordered_set<int>set2;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    set1.insert(i);
                    set2.insert(j);
                }
            }
        }
        for(auto &it:set1){
            for(int i=it,j=0;j<matrix[it].size();j++){
                matrix[i][j]=0;
            }
        }
        for(auto &it:set2){
            for(int i=0,j=it;i<matrix.size();i++){
                matrix[i][j]=0;
            }
        }
    }
};


// setting zeros in first row and colomns instead of using extra space
class Solution{
    public:
    void setZeroes(vector<vector<int> > &matrix) {
        int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

        for (int i = 0; i < rows; i++) {
            if (matrix[i][0] == 0) col0 = 0;
            for (int j = 1; j < cols; j++)
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
        }

        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 1; j--)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            if (col0 == 0) matrix[i][0] = 0;
        }
    }
};