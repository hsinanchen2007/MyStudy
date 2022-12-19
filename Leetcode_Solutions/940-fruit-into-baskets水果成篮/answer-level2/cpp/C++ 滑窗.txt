滑窗，用map记录每种水果最后出现的下标index，map的大小超过2时，对左指针做移动操作

```c++
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        map<int, int> m;    // key-tree[i], value-last index
        int ans = 0;
        int l = 0;
        int pre = 0;        // 记录上一个水果种类
        for (int r = 0; r < tree.size(); r++) {
            m[tree[r]] = r;
            if (m.size() > 2) {
                for (auto& it : m) {        // 找到不等于pre、tree[i]的元素删掉
                    if (it.first != pre && it.first != tree[r]) {
                        l = it.second + 1;  // 左指针 = 最后出现的index + 1
                        m.erase(it.first);
                        break;
                    }
                }
            }
            ans = max(ans, r - l + 1);
            pre = tree[r];
        }
        return ans;
    }
};
```


