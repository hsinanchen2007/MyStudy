### KMP算法的keypoint在于求next数组
**步骤**
- 设定两个指针，一个为字符串移动指针j，另外一个为失匹配返回指针k
- 设定模板字符串为s、k失去匹配之后，往前撤到位置next数组
- 一开始初始时，j、k都在开头，但第一个失匹配的时候k无法往后再退，故设为-1，此时移动j指针（j++）
- 若s[j] == s[k]， 即匹配，则j、k均往后移动
- 如果s[j] != s[k]，即失去匹配，则k要往前撤，此时往前撤的位置，即为next[k]
- 最后如果上面看不懂，建议百度一下KMP，对着模板图死磕一下午你就懂了。
- 以上是一个小白的经验
```
class Solution {
public:
    int next[100005];
    void KMP(string s) {
        int k = -1, j = 0;
        next[0] = -1;
        while(j < s.length()) {
            if(k == -1 || s[j]==s[k]) next[++j] = ++k;
            else {
                k = next[k];    // 指针回退
            }
        }
    }
    string longestPrefix(string s) {
        KMP(s);
        int l = next[s.length()];
        return s.substr(0, l);
    }
};
```
