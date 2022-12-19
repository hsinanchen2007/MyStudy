### 解题思路
执行用时 :4 ms, 在所有 C++ 提交中击败了99.78%的用户

1. 如果是ASCII编码的字符串，那么使用26位的数组还记录每个字符出现的次数就行了，然后用另一个字符串对应的去减。
2. 如果结果整个数组都是0，那么返回true。否则返回false。
3. 如果是unicode，则可以使用 unordere_map 即哈希表来存储个数。否则上述方案效率更高，实现也简单。

### 代码

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        if (n1 != n2) return false;

        int arr[26]; memset(arr, 0, sizeof(arr));
        for (auto w : s) arr[w-'a']++;
        for (auto w : t) arr[w-'a']--;
        for (auto c : arr) if (c>0) return false;

        return true;
    }
};
```