### 解题思路
我现在有点蒙，突然想到的一个思路时间复杂度O(n),空间复杂度O(1),可是不造为啥比别人速度慢了那么多（修改之前是2ms）
不管了，看题
1. 要满足里面可以放雨水，必须要有满足两边的高度高于中间的（即先判断递减再考虑递增）
2. 观察放完雨水后的情况，
-     发现到最高点之前已经不存在递减的情况
-     将到最高点之前的坑全填平了，而从末尾到最高点也是同样的道理
3. 寻找到最高点（如果有n多个最高点，任何一个都是可以的）记录为*maxi*
4. 从数组左端到*maxi*遇到一个坑就给它填到和前一个相等的高度即可，只要*height[left]* <= *height[left - 1]* 就放雨水 
5. 右端开始到maxi也是一样，只要注意边界条件就可以*AC*



找到问题所在了，三目运算符太浪费时间了
```
maxi = height[maxi] > height[i] ? maxi : i;
修改为
if(height[maxi] <= height[i])
maxi = i;
就可以了
```

### 代码

```java
class Solution {
    public int trap(int[] height) {
        if(height.length < 3)
        {
            return 0;
        }
        int maxi = 0;
        int result = 0;
        for(int i = 0; i < height.length; i++)
        {
            maxi = height[maxi] > height[i] ? maxi : i;
        }
        for(int i = 1; i < maxi; i++)
        {
            if(height[i] < height[i - 1])
            {
                result += height[i - 1] - height[i];
                height[i] = height[i - 1];
            }
        }
        for(int i = height.length - 2; i > maxi; i--)
        {
            if(height[i] < height[i + 1])
            {
                result += height[i + 1] - height[i];
                height[i] = height[i + 1];
            }
        }
        return result;
    }
}
```