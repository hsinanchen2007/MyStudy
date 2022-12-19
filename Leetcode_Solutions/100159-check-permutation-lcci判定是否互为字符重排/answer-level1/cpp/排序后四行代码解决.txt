这个很好理解，排完序后相等就一定可以重排。
直接上代码：

```
bool CheckPermutation(string s1, string s2) {
       if(s1.size()!s2.size()) return false;
       sort(s1.begin(),s1.end());
       sort(s2.begin(),s2.end());
       return s1==s2;
    }
```
