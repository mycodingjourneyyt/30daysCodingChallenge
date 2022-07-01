class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int numRows = matrix.size();
        int numCols = matrix[0].size();
        // loop for setting 0th row and 0th column 0 corresponding to any element in that row or column
        // for i,j -> it will set 0 in matrix[i][0] and matrix[0][j]
        // if j==0 and element is 0 then set col0 as 0 because matrix[0][j] can show for both rows and columns
        int col0=1;
        for(int i=0; i<numRows; i++){
            for(int j=0; j<numCols; j++){
                // if j ==0 and element is 0
                if(j==0 && matrix[i][j]==0){
                    col0 = 0;
                }
                // if element is 0
                else if(matrix[i][j]==0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        // iterate from right bottom element of the matrix, matrix[rows-1][cols-1] to matrix[0][0]
        for(int i=numRows-1; i>=0; i--){
            for(int j=numCols-1; j>=0; j--){
                // if j==0 and col0 ==0 then make it 0
                if(j==0 && col0 == 0){
                    matrix[i][j]=0;
                }
                // for all other element if column is not 0
                if(matrix[i][0]==0 || matrix[0][j]==0 && j!=0){
                    matrix[i][j]=0;
                }
                
            }
        }
    }
};