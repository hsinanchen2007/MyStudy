### 解题思路
遍历small中的字符串，在大串中连续使用find查找

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        vector<vector<int>> output;
        for (int i = 0; i < smalls.size(); i++){
            string temp = smalls[i];
            vector<int> search;
            if(!temp.size()){
                output.push_back(search);
                continue;
            }
            int start = 0;
            while ((start = big.find(temp, start))!=string::npos){
                search.push_back(start++);
            }
            output.push_back(search);
        }
        return output;
    }
};
```