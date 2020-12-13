class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        int n=a.size();
        vector<vector<int>> sums(n);
        
        for(int i=0;i<a.size();i++){
            sums[i]={a[i]+b[i],a[i],b[i]};
        }
        sort(sums.rbegin(),sums.rend());
        
        vector<int> result(2,0);
        for(int i=0;i<n;i++){
            result[i%2]+=sums[i][i%2 + 1];
        }
        
        if (result[0] > result[1]) {
            return 1;
        }
        else if (result[0] < result[1]) {
            return -1;
        }
        return 0;
        
    }
};