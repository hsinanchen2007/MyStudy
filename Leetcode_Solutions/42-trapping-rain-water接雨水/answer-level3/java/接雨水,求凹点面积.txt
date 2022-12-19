### 解题思路
![image.png](https://pic.leetcode-cn.com/6e2e1dc8588830b5ad477510b4756865f699957dea7d864a21d0a82bd3e6821e-image.png)

![image.png](https://pic.leetcode-cn.com/b18b45ac03c7babd12f1e2b858eb7ce1005f3e71a99a1d016e3a8b10097e1d4c-image.png)
凹点必须有至少三个数组成每一个凹点的面积是(Math.min(height[j], height[i]) * (j - i - 1)) - (max * (j - i - 1)),其中i是左边界,j是右边界max是i到j之间中最大的值,这是每一个凹点的面积,全部累加得到最终结果

### 代码

```java
class Solution {
    public  int trap(int[] height) {
        int result = 0;
        for (int i = 0; i < height.length - 2; i++) {
            //如果左边界小于等于他的下一次值,即height[i] <= height[i + 1]那么左边界向右移动,因为以i为左边界的凹点一定不存在了,向右移动
            if (height[i] <= height[i + 1]) {
                continue;
            }
            //记录i到j中存在的最大值
            int max = height[i + 1];
            //因为最少三个才能形成凹点,所以j从i+2开始
            for (int j = i + 2; j < height.length; j++) {
                //如height[j]<max说明j不会是右边界,j向右移动
                //height[j]>max说明j作为右边界时候,存在凹点,计算凹点的面积
                if (height[j] > max) {
                    //如果height[j] < height[i]说明右边界小于左边界的值,但是大于max,那么计算出凹点面积之后继续循环,
                    //直到height[j]>=height[i]
                    if (height[j] < height[i]) {
                        //计算凹点面积
                        result = result + (Math.min(height[j], height[i]) * (j - i - 1)) - 
                            (max * (j - i - 1));
                        //如果j已经到边界了,那么就跳出循环,否则max = height[j],继续循环
                        if (j + 1 >= height.length) {
                            break;
                        } else {
                            max = height[j];
                        }
                    } else {
                        //height[j]>=height[i]说明i到j之间的凹点都被计算了,j如果在右移的话以i为左边界到j+1肯定不满足凹点了
                        //因为中间存在height[j],跳出循环即可
                        result = result + (Math.min(height[j], height[i]) * (j - i - 1)) - 
                            (max * (j - i - 1));
                        break;
                    }
                }
            }
        }
        return result;
    }
}
```