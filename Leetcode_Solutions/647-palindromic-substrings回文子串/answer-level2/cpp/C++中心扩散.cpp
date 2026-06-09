

``` C++
class Solution {
public:
    int countSubstrings(string s) {
        int res=0;
        //当前位置（i）作为中心位置向两边扩散或（i,i+1）向两边扩散
        for(int i=0;i<s.size();i++)
        {
            res+=help(s,i,i);//（i）作为中心位置向两边扩散
            res+=help(s,i,i+1);//（i,i+1）向两边扩散
        }
        return res;
    }
    
    int help(string s,int start,int end)
    {
        int count=0;
        while(start>=0&&end<s.size())
        {
            if(s[start]==s[end])
            {
                start--;
                end++;
                count++;
            }
            else
                break;
        }
        return count;
    }
};
```