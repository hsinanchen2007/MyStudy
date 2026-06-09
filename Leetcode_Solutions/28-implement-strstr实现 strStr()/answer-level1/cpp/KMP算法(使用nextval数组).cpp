### 解题思路
本人设定初始下标为1

### 代码

```cpp
class Solution 
{
public:
    int Slen,Tlen;

    int strStr(string S, string T) 
    {
        Slen=S.size(),Tlen=T.size();
        return KMP("0"+S,"0"+T)-1;
    }

    //KMP算法
    int KMP(string S,string T)
    {
        if(Tlen==0) return 1;

        vector<int> nextval(Tlen+1,0);
        GetNextval(T,nextval);

        int i=1,j=1;
        while(i<=Slen && j<=Tlen)
        {
            if(j==0 || S[i]==T[j]) i++,j++;
            else j=nextval[j];
        }

        if(j>Tlen) return i-Tlen;
        else return 0;
    }

    //根据待查找字符串求nextval
    void GetNextval(string T,vector<int>& nextval)
    {
        int j=1,k=0;
        nextval[j]=k;
        vector<int> next=nextval;

        while(j<Tlen)
        {
            if(k==0 || T[j]==T[k])
            {
                next[j+1]=k+1;

                if(T[j+1]!=T[next[j+1]]) nextval[j+1]=next[j+1];
                else nextval[j+1]=nextval[next[j+1]];

                j++,k++;
            }
            else k=nextval[k];
        }
    }
};
```