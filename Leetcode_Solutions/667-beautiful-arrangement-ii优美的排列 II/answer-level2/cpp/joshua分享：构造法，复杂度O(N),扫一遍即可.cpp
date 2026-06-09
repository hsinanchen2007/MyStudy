### 解题思路
joshua分享：构造法，复杂度O(N),扫一遍即可。

### 代码

```cpp
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        int up = 1, down = n;

        // 先把前面的 k-1 个数构造好。
        while(true) {
            ans.push_back(up++);
            if(ans.size() == k) break;
            ans.push_back(down--);
            if(ans.size() == k) break;
        } 
        // 最后把其余的所有元素加进去即可,只需要判断当前是需要递减还是递增，
        // 因为必须要和上一次的数据保持等距。
        if(k % 2 == 1)  while(ans.size() < n) ans.push_back(up++);
        else            while(ans.size() < n) ans.push_back(down--);

        return ans;
    }
};
```