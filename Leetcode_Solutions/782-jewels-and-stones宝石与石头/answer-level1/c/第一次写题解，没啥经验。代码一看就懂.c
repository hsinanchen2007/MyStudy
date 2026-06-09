class Solution
 {
public:
    int numJewelsInStones(string J, string S)
    {
        char Jmap[256]={0};
 
        int result=0;
        for(int i=0;i<J.length();i++)
        {
            Jmap[J[i]]=1;
        }
        for(int j=0;j<S.length();j++)
        {
            if(Jmap[S[j]]==1) result++;
        }
        
        return result;
    }
};