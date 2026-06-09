### 解题思路
多关键字排序。字母可以提前排好序，然后冒泡
### 代码

```cpp
class Solution {
public:
struct rank{
    char name;
    int num[26]={0};
};
    string rankTeams(vector<string>& votes) {
        if(votes.size()==1)
        return votes[0];
        if(votes[0].size()==1)
        return votes[0];
        rank r[26];
        for(int i=0;i<26;i++)
        {
            r[i].name=65+i;//初始化26个字母
        }
        for(int i=0;i<votes.size();i++)
        {
            string s(votes[i]);
            for(int j=0;j<s.size();j++)
            {
                int x=s[j]-65;//是哪个字母就放到哪个字母那去
                r[x].num[j]++;//第j的次数加1
            }
        }
        int len=votes[0].size();
        for(int i=0;i<len;i++)
        {
            for(int j=25;j>0;j--)//冒泡选出参加比赛队伍的顺序
            {
                int k=0;//多关键字排序
                if(r[j].num[k]>=r[j-1].num[k])
                {
                    while(r[j].num[k]==r[j-1].num[k]&&k<len)
                    k++;
                    if(r[j].num[k]>r[j-1].num[k])
                    {
                        rank tmp;
                        tmp=r[j];
                        r[j]=r[j-1];
                        r[j-1]=tmp;
                    }
                }
            }
        }
        string str;
        for(int i=0;i<len;i++)
        {
            str+=r[i].name;
        }
        return str;
    }
};
```