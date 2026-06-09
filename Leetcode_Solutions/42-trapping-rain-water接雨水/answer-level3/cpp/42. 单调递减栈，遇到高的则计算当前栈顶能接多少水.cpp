![image.png](https://pic.leetcode-cn.com/490a4897740bd31b6263fa76774462fb6d22068413e90cf78c3e926be9181d9c-image.png)

### 解题思路
单调栈的实战。记录几个要点。
- 初始位置并不能统一，及时stack里先push(-1),其实意义也不是很大。也就是说起始位置就是要单独讨论。
- height数组的最后也不用放一个哨兵，也就是说，本题中所有的数据都会入栈，但并不一定所有的数据都出栈。
- 还有一个思维上比较tricky的地方，就是计算当前出栈位置接的水的时候，高度可能是0，而该位置其实是可以接水的，但是这并不影响，因为他之所以是0，是因为栈中他左侧的柱子A高度和她相同，那么那个柱子A或者更左边的柱子在计算的时候会将这个没算在内的柱子接的水，一并算在内。

### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        st.push(-1);
        int sum = 0;
        for(int i=0; i<height.size(); i++){// 入
            int topIndex = st.top();
            // 出栈
            while(topIndex!=-1 && height[topIndex]<height[i]){
                st.pop();
                int left = st.top();
                if(left == -1) break;
                int h = min(height[left], height[i])-height[topIndex]; // 注意有的时候可能为0
                sum += h * (i - left - 1);
                topIndex = left;
            }
            st.push(i);
        }
        return sum;
    }
};
```