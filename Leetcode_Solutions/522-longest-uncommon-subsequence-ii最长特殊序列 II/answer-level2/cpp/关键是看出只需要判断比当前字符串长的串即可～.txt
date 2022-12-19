### 解题思路
如题，只需要判断当前串是否为比当前串长的字符串的子序列即可～

### 代码

```cpp
class Solution {
public:
    int judge(string& tp1,string& tp2)
    {
        int i=0,j=0;
        while(j<tp2.size()&&i<tp1.size())
        {
            if(tp1[i]==tp2[j])
            {
                ++i;++j;
            }
            else
                ++j;
        }
        if(i==tp1.size())
            return 1;
        return 0;
    }
    int findLUSlength(vector<string>& strs) {
        int count=-1;
        for(int i=0;i<strs.size();++i)
        {
            int flag=0;
            for(int j=0;j<strs.size();++j)
            {
                if(i!=j&&strs[j].size()>=strs[i].size())
                {
                    int flag1=judge(strs[i],strs[j]);
                    if(flag1==1)
                    {
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==0)
            {
                int lt=strs[i].size();
                if(lt>count)
                    count=lt;
            }
        } 
        return count;
    }
};
```