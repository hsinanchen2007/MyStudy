对n的奇偶性进行判断，如果是奇数，直接n个a
否则 n-1个a + 1个b
```
class Solution {
public:
    string generateTheString(int n) {
        string s;
        for(int i=0;i<n-1;i++) s+='a';
        if(n%2==0) s+='b';
        else s+='a';
        return s;
    }
};
```
