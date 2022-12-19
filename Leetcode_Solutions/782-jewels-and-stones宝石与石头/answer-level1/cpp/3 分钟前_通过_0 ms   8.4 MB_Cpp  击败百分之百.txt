


将他们进行排序，从S中找到第一个J中的字符，之后进行匹配，当出现不符合的字符，跳出循环，使用S的下一个字符再搜索J中的串，以此类推。

class Solution {
public:
    char a[51];
    int numJewelsInStones(string J, string S) {
        memset(a,' ',sizeof(a));
        
        int len=S.length();
        
        for(int i=0;i<len;i++)
            a[i]=S[i];
        sort(a,a+50,greater<int>());
        
        int Jlen=J.length();
        int count=0;
        for(int i=0;i<Jlen;i++)
        {
            bool f=false;
            for(int j=0;j<len;j++)
            {
                if(J[i]==a[j])
                {
                    f=true;
                    if(f)
                    {
                        count++;
                    }
                    if(J[i]!=a[j+1])
                    {
                        f=false;
                        break;
                    }
                }
            }
        }
        return count;
    }
};