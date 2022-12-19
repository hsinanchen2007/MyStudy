### 分析
对于每根柱子，找到其左边的最大值，右边的最大值，然后两者中的较小的减去本根柱子的高度，就是本根柱子上能存放的雨水。
比如 7  4  5   6
因为7是最左边的数，因此，本根柱子能存放的雨水为0，
对于4，其左边的最大值为7，右边的最大值为6.本根柱子能存放的雨水为min(7,6) - 4  = 2
对于5，其左边的最大值为7，右边的最大值为6.本根柱子能存放的雨水为min(7,6) - 1  = 1
因为6是最右边的数，因此，本根柱子能存放的雨水为0。
因此我们可以建两个数组left[]用来存放某个位置左边的最大值、right[]用来存放某个位置左边的最大值
min(left[i],right[i]) - height[i]就是本位置能存放雨水的值。
### 代码
```java
public int trap2(int[] height) {
        if (height == null || height.length < 3) {
            return 0;
        }
        int sum = 0;
        //left[i]表示第i列左边的最高的列值,包含
        int[] left = new int[height.length];
        left[0] = height[0];

        for (int i = 1; i < height.length; i++) {
            left[i] = left[i - 1] > height[i] ? left[i - 1] : height[i];
        }

        int[] right = new int[height.length];
        right[height.length - 1] = height[right.length - 1];
        for (int i = height.length - 2; i >= 0; i--) {
            right[i] = right[i + 1] > height[i] ? right[i + 1] : height[i];
        }
        for (int i = 1; i < height.length - 1; i++) {
            sum += Math.min(left[i], right[i]) - height[i];

        }
        return sum;

    }
```
	
本人建了一个公众号用于刷题交流，欢迎关注
![qrcode_for_gh_8eedbc428c9a_258(1).jpg](https://pic.leetcode-cn.com/e5f794b173fbe256a541447fc7ff8e6eb031774890bdfdb48ca3c786dc81dc2-qrcode_for_gh_8eedbc428c9a_258\(1\).jpg)