### 解题思路
![截屏2020-03-18上午9.33.09.png](https://pic.leetcode-cn.com/6dbb4e1694440472095240013e25419762b352e70c440c61e79d7646802a22fb-%E6%88%AA%E5%B1%8F2020-03-18%E4%B8%8A%E5%8D%889.33.09.png)

我们把已经存在的矩形当作是 rec1, 而带判断矩形是 rec2。

考虑2个边界: 最关键的是看好两个最重要的点，左下角和右上角。最下角代表了整个矩形最小的边界值，而右上角代表最大。

1. 图片中的 AB,CD 两条边所在的直线是我们 rec2 x的取值范围。如果 rec2的**右上角**在**E**点(最远在AB所在的直线上)或者rec2的**左下角**在**H**点(最近在CD所在的直线)这两种情况下都不能有重叠的面积。
2. 再考虑y轴的边界，考虑图中AC,BD两条边界。如果 rec2的**右上角**在**K**点(最近在AC所在的直线上)或者rec2的**左下角**在**N**点(最远在BD所在的直线上) 这两种情况也不会有重叠的面积。
3. 考虑剩余情况是否都会有重叠面积。
4. 不重复，不遗漏，分类讨论结束。

### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        //rec1[x1,y1,x2,y2]
        //rec2[x1,y1,x2,y2]

        if(rec2[0] >= rec1[2] || rec2[2] <= rec1[0])
            return false;
        else if(rec2[1] >= rec1[3] || rec2[3] <= rec1[1])
            return false;

        return true;


    }
}
```