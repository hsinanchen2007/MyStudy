### 解题思路
找到最大值得下标，前半部分内容递增遍历，后半部分递减遍历。
以前半部分为例，如果在遍历的时候找到比当前指向高度高的值，则将此高度设为前半部分的最高高度，否则，最后结果加上最高高度与寻到高度的差值

### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        if not height:
            return 0
        L = len(height)
        M = max(height)
        idx = height.index(M)
        cur_left = height[0]
        count = 0
        for i in range(1, idx):
            if height[i] > cur_left:
                cur_left = height[i]
            else:
                count += cur_left - height[i]
        cur_right = height[L-1]
        for i in range(L-2, idx, -1):
            if cur_right < height[i]:
                cur_right = height[i]
            else:
                count += cur_right - height[i]

        return count

            
                    

            

```