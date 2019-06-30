class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> vtr(grid[0].size(),0);
        vector<int> vtc(grid.size(),0);
        for(int i=0;i<grid.size();i++){
            int maxi=grid[i][0];
            for(int j=1;j<grid[i].size();j++){
                if(grid[i][j]>maxi){
                    maxi=grid[i][j];
                }
            }
            vtc[i]=maxi;
        }
        
        for(int j=0;j<grid[0].size();j++){
            int maxi=grid[0][j];
            for(int i=1;i<grid.size();i++){
                if(grid[i][j]>maxi){
                    maxi=grid[i][j];
                }
            }
            vtr[j]=maxi;
        }
        int sum=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                sum+=min(vtc[i]-grid[i][j],vtr[j]-grid[i][j]);
            }
        }
        
        return sum;
    }
};