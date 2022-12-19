

方法一：暴力法
步骤：
1、先计算完整面积
2、减去黑色部分剩下粉色部分和蓝色部分
3、从最高点分别向左和向右找次高点，减去对应粉色部分
4、从次高点出发，循环步骤3直到尽头，最后剩下蓝色部分即为答案
5、粉色格内数字代表第n次循环时要减去的部分
![微信图片_20200317160955.png](https://pic.leetcode-cn.com/090a2e2dea2b5802dc88617943177d5849faf38831ffe7ffe9f08904f0528750-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200317160955.png)

```csharp
public int Trap(int[] height)
{
    if (height.Length < 3)
    {
        return 0;
    }
    int maxIdx = 0;
    int maxHeight = 0;
    int sum = 0;
    for (int i = 0; i < height.Length; i++)
    {
        if (height[i] > maxHeight)
        {
            maxIdx = i;
            maxHeight = height[i];
        }
        sum += height[i];
    }
    int area = maxHeight * height.Length - sum;
    int idxLeft = maxIdx, idxRight = maxIdx;
    int preLeft, preRight;
    while (idxRight >= 0 || idxLeft >= 0)
    {
        preLeft = idxLeft;
        preRight = idxRight;
        if (preLeft >= 0)
        {
            idxLeft = FindNextPeek(height, idxLeft, true);
            if (idxLeft >= 0)
            {
                area -= (preLeft - idxLeft) * (maxHeight - height[idxLeft]);
            }
            else
            {
                area -= preLeft * (maxHeight - height[0]);
            }
        }
        if (preRight >= 0)
        {
            idxRight = FindNextPeek(height, idxRight, false);
            if (idxRight >= 0)
            {
                area -= (idxRight - preRight) * (maxHeight - height[idxRight]);
            }
            else
            {
                area -= (height.Length - 1 - preRight) * (maxHeight - height[height.Length - 1]);
            }
        }
    }
    return area;
}

public int FindNextPeek(int[] arr, int idx, bool fromLeft)
{
    if (fromLeft)
    {
        if (idx == 0) return -1;
        int max = arr[0];
        int ans = 0;
        for (int i = 1; i < idx; i++)
        {
            if (arr[i] >= max)
            {
                max = arr[i];
                ans = i;
            }
        }
        return ans;
    }
    else
    {
        if (idx == arr.Length - 1) return -1;
        int max = arr[arr.Length - 1];
        int ans = arr.Length - 1;
        for (int i = arr.Length - 2; i > idx; i--)
        {
            if (arr[i] >= max)
            {
                max = arr[i];
                ans = i;
            }
        }
        return ans;
    }
}
```
方法二：参考题解的左右扫描法
```csharp
public int Trap(int[] height)
{
    if(height == null || height.Length < 3) return 0;
    int left = 0;
    int leftSum = 0;
    int sum = 0;
    for(int i = 0; i < height.Length; i++)
    {
        left = Math.Max(left, height[i]);
        leftSum += left;
        sum += height[i];
    }
    int right = 0;
    int rightSum = 0;
    for(int i = height.Length - 1; i >= 0; i--)
    {
        right = Math.Max(right, height[i]);
        rightSum += right;
    }
    return leftSum + rightSum - sum - left * height.Length;
}
```