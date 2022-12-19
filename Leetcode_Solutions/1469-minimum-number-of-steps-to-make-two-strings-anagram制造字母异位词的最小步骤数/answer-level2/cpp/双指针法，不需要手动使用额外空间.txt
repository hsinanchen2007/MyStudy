这里提供一种不需要额外空间的思路。
即先排序随后使用双指针对相同字符进行配对。
答案为字符串长度减去配对数。
```
class Solution {
public:
    int minSteps(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int i=0,j=0,ans=0,l=s.size();
        while(i<l&&j<l)
        {
            if(s[i]==t[j]) i++,j++,ans++;
            else if(s[i]>t[j]) j++;
            else i++;
            if(j==l||i==l) break;
        }
        return l-ans;
    }
};
```
