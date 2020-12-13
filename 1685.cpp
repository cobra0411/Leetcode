class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> l(n);
        vector<int> r(n);
        
        int sum=0;
        for(int i=0;i<n;i++){
            l[i]=sum;
            sum+=nums[i];
        }
        sum=0;
        for(int i=n-1;i>=0;i--){
            r[i]=sum;
            sum+=nums[i];
        }
        
        vector<int> result(n);
        
        for(int i=0;i<n;i++){
            result[i]=(nums[i]*i-l[i])+(r[i]-nums[i]*(n-1-i));
        }
        return result;
    }
};