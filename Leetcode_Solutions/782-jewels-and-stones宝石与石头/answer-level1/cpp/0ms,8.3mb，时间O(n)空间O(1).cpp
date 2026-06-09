`
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int s[256]={};
        int i=0;
        int res=0;
        while(i<J.size())s[(int)J[i++]]=1;
        i=0;
        while(i<S.size())if(s[(int)S[i++]]==1)++res;
        return res;
    }
};
`
另外++res改成res++时间会多很多？？？
