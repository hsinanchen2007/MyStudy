本解法思路比较简单，采用的是计数法，然后判断每个字符个数的奇偶进行分类处理
```
class Solution {
public:
    int longestPalindrome(string s) {
        int count[58]={0};
        int num=0;
        int max=0;
        for(int i=0;i<s.size();i++)
            count[s[i]-'A']++;
        for(int i=0;i<58;i++)
            if(count[i]%2==0)
                num+=count[i];
            else if(count[i]%2==1)
            {
                max=max>count[i] ?max:count[i];
                if(count!=0)
                {
                    count[i]--;
                    num+=count[i];
                }    
            }
        num= max==0? num:num+1;
        return num;
    }
};
```
