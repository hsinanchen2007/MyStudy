### 解题思路
由于需要先满足first，然后在满足second，有明显先后顺序，要么用队列，要么用状态数记录进度
这里需要考虑到third == first的特殊情况
### 代码

```cpp
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        istringstream iss(text);
        vector<string> res;
        string w;
        int cnt = 0;
        while (iss >> w) {
            switch (cnt) {
            case 0:
                if (w == first) {
                    cnt = 1;
                }
                break;
            case 1:
                if (w == second) {
                    cnt = 2;
                } else if (w == first){
                    cnt = 1;
                } else {
                    cnt = 0;
                }
                break;
            case 2:
                res.push_back(w);
                if (w == first) {
                    cnt = 1;
                } else {
                    cnt = 0;
                }
                break;
            default:
                cnt = 0;
            }
        }
        return res;
    }
};
```