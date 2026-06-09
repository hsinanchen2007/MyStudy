### 解题思路
思路很简单用map把罗马数字和普通数字联系。。。
然后用for循环遍历。。。。

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int sum = mp[s[0]];
        for(int i = 1;i<s.length();i++){
            if(mp[s[i]]>mp[s[i-1]]){
                sum = sum - 2*mp[s[i-1]] + mp[s[i]];
            }
            else sum+=mp[s[i]];
        }
        return sum;
    }
};
```