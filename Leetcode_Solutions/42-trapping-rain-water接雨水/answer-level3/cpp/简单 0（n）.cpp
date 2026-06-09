### 解题思路
思路很简单：
1. 每个柱子的深度： Di = min{leftMax, rightMax} - Hi; (不为负数，否则为0)
2.  就是： 左右最高的柱子之间能 短的就是 储水空间，在减去柱子本身的空间
3. 如果只一遍的话，暂时不知道另一边的柱子最高长度。所以自右向左先遍历一遍，记录每根柱子的rightMax
4. 然后自左向右遍历一边，就可以计算每一根柱子处 多少水了

看了官解：
1. 暴力： 是每根柱子都遍历一次右侧，所以是 n*n
2. 其他的应也是 先存 每根柱子的 一侧最高值

### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        if (n < 3)
            return 0;

        vector<int> right_max(n, 0);

        int max = height[n-1];
        for (int i=n-2; i>=0; i-- ){
            right_max[i] = max;                 // 每个点的 right_MAX, 自己不算
            if (height[i] > max){
                max = height[i];
            }
        }

        int sum = 0;
        int leftmax = height[0];
        for (int i=1; i<n-1; i++){
            int min = leftmax < right_max[i] ? leftmax : right_max[i];
            sum += min > height[i] ? min - height[i] : 0;
            if (height[i] > leftmax){
                leftmax = height[i];
            }
        }

        return sum;
    }
};
```