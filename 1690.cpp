class Solution {
public:
    int dp2[1001][1001];
    int solve(vector<int> &stones,int i,int j,vector<vector<int>> &dp){
        
        if(j<i){
            return 0;
        }
        if(i==j){
            return 0;
        }
        if(dp2[i][j]){
            return dp2[i][j];
        }
        
        int result=dp[i][j-1]-solve(stones,i,j-1,dp);
        
        result=max(result,dp[i+1][j]-solve(stones,i+1,j,dp));
        
        dp2[i][j]=result;
        
        return result;
        
        
    }
    
    
    int stoneGameVII(vector<int>& stones) {
        
        int n=stones.size();
        memset(dp2,0,sizeof(dp2));
        vector<vector<int>> dp(n,vector<int> (n,0));
        
        for(int i=0;i<n;i++){
            int sum=0;
            
            for(int j=i;j<n;j++){
                sum+=stones[j];
                dp[i][j]=sum;
            }
        }
        
        int result=solve(stones,0,n-1,dp);
        return result;
    }
};