class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> ok(26,0);
        
        for(int i=0;i<allowed.size();i++){
            ok[allowed[i]-'a']=1;
        }
        
        int result=0;
        for(int i=0;i<words.size();i++){
            int flag=0;
            for(int j=0;j<words[i].size();j++){
                if(ok[words[i][j]-'a']!=1){
                    flag=1;
                }
            }
            if(flag==0){
                result++;
            }
        }
        return result;
    }
};