class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int pc, int mb, int mw) {
        
       int m=boxes.size();
        int i=0;
        vector<int> dp(m+1,0);
        int cost=1;
        int wt=0;
        
        for(int j=0;j<m;j++){
            
            if(j==0||boxes[j][0]!=boxes[j-1][0]){
                cost++;
            }
            wt+=boxes[j][1];
            
            while(j-i+1>mb||wt>mw||(i<j and dp[i+1]==dp[i])){
                wt-=boxes[i][1];
                
                if(boxes[i][0]!=boxes[i+1][0]){
                    cost--;
                }
                i++;
            }
            dp[j+1]=dp[i]+cost;
            
        }
        return dp[m];
        
    }
};