### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string simplifyPath(string path) {
        if (path.empty()) return "/";
        int ddot_num = 0;
        string effect_path;
        string temp_path;
        bool flag = 0;
        vector<string> temp1_path;
        for (int i = path.size() - 1; i >= 0;--i) {
            if (path[i] == '/') {
                if (flag) {
                    temp1_path.push_back(temp_path);
                    temp_path.clear();
                    flag = 0;
                }
                continue;
            }
            
            temp_path += path[i]; 
            flag = 1; 
        }

        string root = "/";
        for (int i = 0; i < temp1_path.size(); ++i) {
            if (temp1_path[i] == "..") {
                ddot_num++;
                continue;
            }

            if (temp1_path[i] == ".") continue;
            if (ddot_num) {
                ddot_num--;
                continue;
            }

            effect_path += root + temp1_path[i] ;

        }
        
        if (effect_path.empty()) return root;
        reverse(effect_path.begin(), effect_path.end());
        effect_path = root + effect_path;
        effect_path.pop_back();
        return effect_path;
    }
};
```