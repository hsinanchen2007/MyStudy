排除法
两矩阵投影到坐标轴上，把两维问题转为一维问题。我们可以得知，不重叠的只有两种情况。
然后，我们将不重叠的情况**取反**就得到重叠的情况，横轴和竖轴进行与运算返回，就可以得到结果。
![微信截图_20200318232118.jpg](https://pic.leetcode-cn.com/501760d497ce4bb3355423db65ed6cf13774cfd9dbb8e40e77c189d918d7d56f-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200318232118.jpg)

![微信截图_20200318232133.jpg](https://pic.leetcode-cn.com/0c8370aed3690507ccdc7b7761f897e9400f7442f3225e1a5450fc54ea731e27-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200318232133.jpg)

```
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        boolean x_overlap = !(rec1[2] <= rec2[0] || rec2[2] <= rec1[0]);
        boolean y_overlap = !(rec1[3] <= rec2[1] || rec2[3] <= rec1[1]);
        return x_overlap && y_overlap;
    }
}
```
