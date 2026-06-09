![image.png](https://pic.leetcode-cn.com/30e7165aec91d2d1e44fbbc67807af5912380fcf4ebc0bdc8c6308679258cd93-image.png)

### 解题思路
1、凹处即为可积水处，转换为数学，就是数组中的峰值之间。
2、从左到右依次遍历独立的凹处，叠加得到最后结果。在这种方式下，什么是独立？
(1)取一处为左柱，当首次遇到一个高度大于或等于左柱的右柱时，其间的凹处具有独立性。可脑补：右边就算有更高的柱，也对其无任何影响。
(2)取一处为左柱，当右测的柱都比左柱低时，取右侧最高的柱作为右柱，组成独立凹处。
3、对于每一个有效水坑，积水值计算方法一致：左右柱间可容最大值(低的柱高乘以间距)减去其间其他柱占用的容量。
4、由于只从左到右遍历一次, 时间复杂度为O(n)。

### 代码

```c
int trap(int* height, int heightSize)
{
    int i, j = 0;
    int iLeft = 0;
    int iRight = 0;
    int iRightHigh = 0;
    int iMinHigh = 0;
    int iCnt = 0;
    int iTotalCnt = 0;

    for (i = 0; i < heightSize - 1; )
    {
        iLeft = i;
        iRight = i;
        iRightHigh = 0;
       
        i++;
        while (1)
        {   
            /* 寻找到下一个不低于左柱的右柱，直接返回 */
            if (height[i] >= height[iLeft])
            {
               iRight = i;
               break;
            }
           
            /* 记录右侧目前找到的最高柱 */
            if (height[i] > iRightHigh)
            {
                iRightHigh =  height[i];
                iRight = i; 
            }
```
代码块
```

            if (i < heightSize - 1)
            {
               i++;
            }
            else 
            {
               break;
            }
        }

        if (iRight <= iLeft + 1)
        {
            i = iLeft + 1;
            continue;
        }
       
        /* 计算局部雨量: 两柱间的最大容积减去其中柱占用容积 */
        iMinHigh = (height[iLeft] > height[iRight]) ? height[iRight] : height[iLeft];
        iCnt = iMinHigh * (iRight - iLeft - 1);
        for (j = iLeft + 1; j < iRight; j++)
        {
            iCnt -= (height[j] > iMinHigh) ? iMinHigh : height[j];
        }

        iTotalCnt += iCnt; 

        /* 下一次循环以右柱作为新左柱 */
        i = iRight;
    }

    return iTotalCnt; 
}
```