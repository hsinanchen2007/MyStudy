### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isStrobogrammatic(string num) {
        string temp;
        unordered_map<char, char> tmp={{'6', '9'}, {'9', '6'}, {'8', '8'}, {'1', '1'}, {'0', '0'}};
        for(int i = num.size() - 1; i >= 0; i--){
            if(tmp.find(num[i]) == tmp.end()) return false;
            else {
                temp += tmp[num[i]];
            }
        }
        return temp == num;
    }
};
```