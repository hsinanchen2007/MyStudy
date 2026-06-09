```
public boolean isRectangleOverlap(int[] rec1, int[] rec2)
    {
        if (rec1[1] > rec2[1])
        {
            return isRectangleOverlap(rec2,rec1);
        }
//先要求第一个矩形的左下角的点的y轴比第二个矩形左下角的点小
        if (rec2[0] > rec1[0] && rec2[0] < rec1[2] && rec2[1] < rec1[3])
        {
            return true;
        }
//如果第二个矩形左下角的点在区域5，那么必定是包含的，注意我这边只取了下边界，其他边界没取。
        else return rec2[0] <= rec1[0] && rec2[1] < rec1[3] && rec2[2] > rec1[0];
//如果第二个矩形的左下角的点在区域4，那个第二的矩形的右上角的点在2，3，5，6区域均可，我第二个矩形左下角取到了区域5的左边界，因为矩形的左下角和右上角不会是同一个x，因此也不需要其他的约束了。
其余均不行
    }
```
![微信截图_20200318155826.png](https://pic.leetcode-cn.com/5bcc3aa1926ca29a80f3b0b2a5a63179f2f0cdf1e0ac1014aad823bb20051baa-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200318155826.png)
