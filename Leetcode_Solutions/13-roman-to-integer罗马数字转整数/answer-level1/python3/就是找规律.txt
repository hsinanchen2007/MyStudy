```C++ []
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> map = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int slen = s.length();
        int sum = 0;
        for(int i = 0;i<slen;i++)
        {
            if (i+1<slen && map[s[i]] < map[s[i+1]])
                sum -= map[s[i]];//如果前一个小于后面一个直接减去相应的值
            else
                sum += map[s[i]];//否则直接加上对应的值

        }
        return sum;
    }
};
```
```python []
class Solution:
    def romanToInt(self, s: str) -> int:
        kv = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        num = 0
        flag = 0
        for i in range(len(s)):
            if i+1 < len(s) and kv[s[i]] < kv[s[i+1]]:
                flag = 1
                continue
            if flag == 1:
                num += (kv[s[i]]-kv[s[i-1]])
                
                flag  = 0
                continue
            num += kv[s[i]]
        return int(num)

```