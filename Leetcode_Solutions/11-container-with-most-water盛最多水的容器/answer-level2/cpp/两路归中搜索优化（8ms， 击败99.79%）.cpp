### 解题思路
算式：(r - l) * min(height[r], height[l])
因为我们要找的是最大解，从最两边来找的话，那肯定是把两边中的相对短的边改变才可以得到更优解，且相对短的边只有变长才有可能使得解变大，因为两边的距离(r - l)在缩小的前提下只有让高度提高才可能有更优解。

### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0, size = height.size(), l = 0, r = size - 1;
        while (r > l) {
            ans = max(ans, (r - l) * min(height[r], height[l]));
            if (height[r] > height[l]) {
                int now = height[l++]; // 记录短的边
                while (r > l && height[l] <= now) ++l; //直到找到更高的边为止一直查找 
            }
            else {
                int now = height[r--]; // 和上同理
                while (r > l && height[r] <= now) --r;
            }
        }
        return ans;
    }
};
```