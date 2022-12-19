先确立一个最高点，两边向山顶爬山，只要遇到凹坑，就填水。


### 代码

```java
class Solution {
    public int trap(int[] height) {
        int len = height.length;
        if (len < 3)
            return 0;

        int maxData =height[0] , maxIndex = 0;
        for (int i = 0 ; i < len ; i ++) {
            maxIndex = (height[i] > maxData ? i : maxIndex);
            maxData = (height[i] > maxData ? height[i] : maxData);
        }

        int i = 0 , j = len - 1;
        int res = 0;
        while (i < maxIndex || j > maxIndex) {
            int tempData1 = height[i];
            while (i < maxIndex && height[i] <= tempData1) {
                res += (tempData1 - height[i++]);
            }

            int tempData2 = height[j];
            while (j > maxIndex && height[j] <= tempData2) {
                res += (tempData2 - height[j--]);
            }
        }
        return res;
    }
}
```