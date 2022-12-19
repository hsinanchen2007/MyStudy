### 解题思路

使用一个大小为128的int类型数组存放字符出现的次数，先遍历s记录字符出现次数，再遍历t时出现则递减1。
最终若两字符串互为字母异位词，则这个int数组所有元素应当都为0。

执行用时 :8 ms, 95.68%
内存消耗 :9.1 MB, 99.85%

代码如下

### 代码

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        int M[128] = {0};
        for (char c : s)
            M[c]++;
        for (char c : t)
            M[c]--;
        for (int i = 0; i < 128; i++)
            if (M[i] != 0)
                return false;
        return true;
    }
};
```