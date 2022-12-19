### 解题思路
解法一： 乐观估计法，想象短板在左，长板在右边
1: 设置两个指针，参考指针 bIdx, 移动指针 tIdx
2: 参考高度和移动高度进行比较， <= 移动高度，说明遇到右边长板，参考指针跳到移动指针位置;  > 移动高度, 则遇到短板，参考高度 - 移动高度 就是两板的雨水数
3: 如果移动指针移动到末尾的下一个位置还是没遇到长板的话，则参考高度大于他右边所有柱子，此时只能反向收集，因为长板在左边

### 代码
```csharp
public class Solution {
    public int Trap(int[] height)
    {
        var bIdx = 0;
        var eIdx = height.Length - 1;
        var tIdx = bIdx + 1;
        var water = 0;
        var tempWater = 0;
        while (bIdx < eIdx)
        {
            if (tIdx > eIdx)
            {
                // 到底了，还没找到长板的话，就要反向收集雨水了
                water += reverseWater(bIdx, eIdx, height);
                tempWater = 0;
                bIdx = tIdx;
                tIdx++;
                continue;
            }

            if (height[bIdx] <= height[tIdx])
            {
                bIdx = tIdx;
                tIdx = bIdx + 1;
                water += tempWater;
                tempWater = 0;
            }
            else
            {
                tempWater += height[bIdx] - height[tIdx];
                tIdx++;
            }
        }

        return water;
    }

    // 反向收集雨水
    int reverseWater(int begIndex, int endIndex, int[] height)
    {
        if (begIndex == endIndex)
            return 0;
        var refIdx = endIndex;
        var moveIdx = refIdx - 1;
        var water = 0;
        var tmpWater = 0;
        while (refIdx > begIndex)
        {
            if (moveIdx == begIndex)
            {
                water += tmpWater;
                break;
            }

            if (height[refIdx] <= height[moveIdx])
            {
                water += tmpWater;
                tmpWater = 0;
                refIdx = moveIdx;
                moveIdx--;
            }
            else
            {
                tmpWater += height[refIdx] - height[moveIdx];
                moveIdx--;
            }
        }

        return water;
    }
}
```

### 解题思路
解法二： 左右开弓法
左右对比，确定长板方向， 短板方趋近于长板方

### 代码
```csharp
public class Solution {
    public int Trap(int[] height)
    {
        // 用短板向长板移动
        var left = 0;
        var right = height.Length - 1;
        var water = 0;
        var leftMax = 0;
        var rightMax = 0;

        while (left < right)
        {
            if (height[left] < height[right])
            {
                if (leftMax < height[left])
                    leftMax = height[left];
                else
                {
                    if (leftMax != height[left])
                        water += leftMax - height[left];
                }
                left++;
            }
            else
            {
                if (rightMax < height[right])
                    rightMax = height[right];
                else
                {
                    if (rightMax != height[right])
                        water += rightMax - height[right];
                }
                right--;
            }
        }

        return water;
    }
}
```