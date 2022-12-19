##### 代码也没几行
```
int vis[256];
class Solution {
public:
    bool isUnique(string astr) {
        fill(vis, vis + 256, 0);
        bool isUnique = true;
        for (int i = 0; i < astr.size(); i++) {
            vis[astr[i]]++;
            // 找到一个hash表里的值大于1即可跳出循环
            if (vis[astr[i]] > 1) {
                isUnique = false;
                break;
            }
        }
        return isUnique;
    }
};
```
