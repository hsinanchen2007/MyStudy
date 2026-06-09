## 思路
利用异或操作性质：两个相同数 a ^ a = 0， a ^ 0 = a.
## 代码
时间复杂度：O(n)
空间复杂度：O(1)
```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int e = 0;
        for (int num : nums) {
            e ^= num;
        }
        return e;
    }
};
```
