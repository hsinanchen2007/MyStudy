### 解题思路
通过直接从前往后遍历，若后者大于当前，则用后者减去之前计算的值得出该部分的将结果，加到总的数值大小中。反之临时存储。但比较疑惑这种方法执行用时为什么那么慢.....有大佬提供高速的代码吗

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mp;
    mp.insert(pair<char,int>('I',1));
    mp.insert(pair<char,int>('V',5));
    mp.insert(pair<char,int>('X',10));
    mp.insert(pair<char,int>('L',50));
    mp.insert(pair<char,int>('C',100));
    mp.insert(pair<char,int>('D',500));
    mp.insert(pair<char,int>('M',1000));
    int num = 0;
    int pre = mp[s[0]];
    for(int i = 0 ; i < s.size(); i++){
        if(mp[s[i]] > mp[s[i + 1]]){
            if(mp[s[i]] > mp[s[i - 1]])
                pre = 2*mp[s[i]] - pre;
            num += pre;
            pre = mp[s[i+1]];
        }
        else{
            pre += mp[s[i+1]];
        }
    }
    return num;
    }
};
```