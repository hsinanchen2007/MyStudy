首尾指针
- 不相等，判断去除前面指针所指字母继续比较或去除后面元素继续比较
- 借助辅助函数判定去除后的字符串是否为回文子串

``` C++
class Solution {
public:
    bool validPalindrome(string s) {
        if(s.size()<=2) return true;
        int start=0,end=s.size()-1;
        while(start<end)
        {
            if(s[start]!=s[end])
            {
                return helper(s,start+1,end)||helper(s,start,end-1);//用++，--不行
                
            }
            start++;
            end--;
        }
        return true;
        
    }
    bool helper(string s,int start,int end)
    {
        while(start<end)
        {
            if(s[start]!=s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
};
```