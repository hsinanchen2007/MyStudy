执行用时 :4 ms, 在所有 C++ 提交中击败了93.20% 的用户
内存消耗 :8.7 MB, 在所有 C++ 提交中击败了81.82%的用户
```
class Solution {
public:
    int lengthOfLastWord(string s) {
     int j=s.size()-1;
        while(j>=0)
        {
            if(s[j]==' ') j--;//找尾；
            else break;
        }
        int i=j;
        while(i<=j&&i>=0)
        {
            if(s[i]!=' ')i--;//找头；
            else break;
        }
        return j-i;
    }
};
```
执行用时 :4 ms, 在所有 C++ 提交中击败了93.20% 的用户
内存消耗 :9.3 MB, 在所有 C++ 提交中击败了11.33%的用户
```
class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream str(s);
        string res;
        while(str)
        {
            str>>res;
        }
        return res.size();
        
    }
};
```