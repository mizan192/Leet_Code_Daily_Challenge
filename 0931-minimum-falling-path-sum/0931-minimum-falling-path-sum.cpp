class Solution {
public:



    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();  
        int minSum=INT_MAX;
       
//all minSum will updated at 0'th row
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
            //stright bottom
                int nextMin = matrix[i+1][j];
            //left bottom
                if(j-1>=0) nextMin=min(nextMin,matrix[i+1][j-1]);
            //right bottom 
                if(j+1<n) nextMin=min(nextMin,matrix[i+1][j+1]);
            //update new min sum
                matrix[i][j]+=nextMin;
            }
        }

        for(int i=0;i<n;i++) minSum=min(minSum,matrix[0][i]);

        return minSum;

    }
};