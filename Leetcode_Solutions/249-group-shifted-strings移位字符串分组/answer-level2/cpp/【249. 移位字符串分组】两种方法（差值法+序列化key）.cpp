## 思路一：差值相同为key
同一组的移位字符串位数相同且**每位字符串差值相同**。
### 代码
时间复杂度：O(n^2)，n为字符串长度。
```c++
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        if (strings.empty()) return {};
        vector<vector<string>> res;
        unordered_map<string, vector<string>> umap;
        bool found = false;
        for (string str : strings) {
            if (umap.empty()) {
                umap[str].push_back(str);
            } else {
                found = false;
                for (auto it : umap) {
                    string key = it.first;
                    if (key.size() != str.size()) continue;
                    int dis = (key[0] + 26 - str[0]) % 26;//防止字符循环
                    int i;
                    for (i = 1; i < key.size(); ++i) {
                        //如果差值不同，则终止
                        if ((key[i] + 26 - str[i]) % 26 != dis) {
                            break;
                        }
                    }
                    //找到相同key的移位字符串
                    if (i == key.size()) {
                        found = true;
                        umap[key].push_back(str);
                    } 
                }
                //没找到单独一组
                if (!found) {
                    umap[str].push_back(str);
                }
            }
        }
        for (auto it : umap) {
            res.push_back(it.second);
        }
        return res;
    }
};
```

## 思路二：序列化key（最优解）
设计key值为字符串中每个字符与第一个字符的差值。同一组移位字符串具有相同差值序列。
### 代码
时间复杂度：O(nk)，n为字符串个数，k为字符串最大长度。
空间复杂度：O(nk)
```c++
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        if (strings.empty()) return {};
        vector<vector<string>> res;
        unordered_map<string, vector<string>> umap;        
        for (string str : strings) {
            string tmp;
            for (auto c : str) {
                tmp += (c - str[0] + 26) % 26;
                tmp += '#';
            }
            umap[tmp].push_back(str);
        }
        for (auto it : umap) {
            res.push_back(it.second);
        }
        return res;
    }
};
```

