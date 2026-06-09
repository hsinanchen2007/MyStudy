承接雨水的结构类似水槽，水面高度取决于左右两边较低的木板，可以直观地联想到双指针法。
双指针法的详细思路可见官方题解，其中还有一处可优化的地方：

由于每次都在左右指针中选取较低者进行遍历，所以存在以下特点：
1）未遍历部分（可具体到对侧）一定存在比已遍历部分（可具体到本侧）任意值都更高的值；
2）当且仅当指针移动后对应的新值大于已遍历的最高值时，左右指针才会更替，且对侧载入的值成为最高值（即 “本侧新值 > 对侧新值 > 原最高值” 时左右发生轮换）；

因此，只需一个值记载已遍历的最大高度，无需分为左右两个值。
```
class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1, h = 0, ans = 0;
        while (l < r)
            if (height[l] < height[r]) 
                (height[l] >= h) ? (h = height[l++]) : (ans += h - height[l++]);
            else 
                (height[r] >= h) ? (h = height[r--]) : (ans += h - height[r--]);
        return ans;
    }
};
```