### 解题思路
把值先全部插入map中，然后遍历字符串， i<i+1 把结果就加s[i+1]-s[i]并且前进两步,  否则就只加s[i],前进一步。

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        if(s.size() == 0)
         return 0;
        map<char,int> m;
        
        m.insert(map<char,int>::value_type('I',1)); 
        m.insert(map<char,int>::value_type('V',5));
        m.insert(map<char,int >::value_type('X',10));
        m.insert(map<char,int >::value_type ('L',50));
        m.insert(map<char,int>::value_type('C',100));
        m.insert(map<char,int>::value_type('D',500));
        m.insert(map<char,int>::value_type('M',1000));
        int ans = 0;
        for(int i = 0;i<s.size();i++)
        {
            if(m[s[i+1]] <= m[s[i]])
            {
                ans += m[s[i]];
                
            }
            else if(m[s[i]] < m[s[i+1]])
            {
                ans += (m[s[i+1]] -m[s[i]]);
                i++;
            }
        }
        return ans;
    }
};
```