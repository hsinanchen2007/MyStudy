### 解题思路
自己写的很慢，，，不熟悉各种容器的用法。
string s . s[0]是一个字符  char, 不是string .比较的时候要注意。

### 代码

```cpp
class Solution {
public:
    // 执行用时 :40 ms, 在所有 C++ 提交中击败了18.03% 的用户
    // 内存消耗 :9 MB, 在所有 C++ 提交中击败了67.01%的用户
    int romanToInt(string s) {
        int res=0;
        vector<int> number = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> letter = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int index = 0;
        for(int i = 0;i<number.size();++i){
            int length = letter[i].size();
            // string temp = s.substr(index,length);
            while(index+length<=s.size()&&s.substr(index,length)==letter[i]){
                res += number[i];
                index += length;
            }
        }
        return res;
    }

    // 执行用时 :52 ms, 在所有 C++ 提交中击败了7.29% 的用户
    // 内存消耗 :7.9 MB, 在所有 C++ 提交中击败了100.00%的用户
    int romanToInt(string s) {
        int res = 0;
        // vector<int> number = {1000, 500, 100, 50, 10, 5, 1};
        // vector<string> letter = {"M", "D", "C", "L", "X", "V", "I"};
        unordered_map<char, int> map = {{'M',1000},{'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
        int index = 0;
        while(index < s.size()){
            if(index+1<s.size() && map[s[index]]<map[s[index+1]]){
                res -= map[s[index]];
            }
            else{
                res += map[s[index]];
            }
            ++index;
        }
        return res;
    }
};
```