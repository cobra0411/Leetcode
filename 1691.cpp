class Solution {
public:
    // number of cuboid=>100
    
    int maxHeight(vector<vector<int>>& cuboids) {
        // sort the dimension
        
        for(int i=0;i<cuboids.size();i++){
            sort(cuboids[i].begin(),cuboids[i].end());
        }
        cuboids.push_back({0,0,0});
        sort(cuboids.begin(),cuboids.end());
        
        int n=cuboids.size();
        
        vector<int> dp(n);
        int result=0;
        
        for(int j=1;j<n;j++){
            // height upto dp[i]
            
            dp[j]=cuboids[j][2];
            for(int i=0;i<j;i++){
                if(cuboids[i][0]<=cuboids[j][0] and cuboids[i][1]<=cuboids[j][1] and cuboids[i][2]<=cuboids[j][2]){
                    dp[j]=max(dp[j],dp[i]+cuboids[j][2]);
                }
            }
            
            result=max(result,dp[j]);
        }
        
        return result;
    }
};