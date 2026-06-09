### 解题思路
思路就是使用双指针i，j，向中间收缩，进行左右夹逼，只需要一次遍历：
1，每次计算出当前面积大小，并与之前的最大面积比较；
2，在向中间夹逼的时候，每次选择当前较低的那个柱子向内收缩一步，保证在宽度缩小时，较高的柱子依旧保留。

### 代码

```cpp
// class Solution {
// private:
//     int max = 0, h = 0;
// public:
//     int maxArea(vector<int>& height) {
//         for (int i = 0; i < height.size() - 1; i++) {
//             for (int j = i + 1; j < height.size(); j++) {
//                 if (height[i] > height[j]) {
//                     h = height[j];
//                 } else {
//                     h = height[i];
//                 }
//                 if (max < h * (j - i)) {
//                     max = h * (j - i);
//                 }
//             }
//         }
//         return max;
//     }
// };

class Solution { 
public:
    int maxArea(vector<int>& height) {
        int m = 0;
        for (int i = 0, j = height.size() - 1; i < j; ) {
            int minHeight = height[i] < height[j] ? height[i++] : height[j --];
            m = max(m, (j - i + 1) * minHeight);
        }
        return m;
    }
};
```