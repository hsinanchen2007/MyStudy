class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int n = S.size();
        int res =0;
        for(int i =0;i<n;++i){
            if(J.find(S[i])!=-1){
                res ++;
            }
        }
        return res;

    }
};

将S从头便利一次，去除单个字符，用string：：find（）方法查找在J中的位置，如果返回非-1则存在res加1