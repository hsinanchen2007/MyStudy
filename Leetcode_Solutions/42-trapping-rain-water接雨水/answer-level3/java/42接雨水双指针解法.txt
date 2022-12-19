```java
public class T42_TrappingRainWater {

    public static void main(String[] args) {
        T42_TrappingRainWater test = new T42_TrappingRainWater();
        System.out.println(test.trap1(new int[]{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}));
    }

    /**
     * 执行用时 :3 ms, 35.51%
     * 内存消耗 :43.3 MB, 5.02%
     * 每个柱子接到的雨水等于这个柱子左右两边最大值中较小者减去柱子本身的高度
     */
    public int trap(int[] height) {
        if (height == null || height.length == 0)
            return 0;
        int len = height.length;
        int[] left = new int[len];
        int[] right = new int[len];
        /*
         * 计算出每一列中左边最高， 右边最高的高度
         * 每一列中包含水滴的个数 = 当前节点两边最大高度的较小值 - 当前节点高度
         */
        left[0] = height[0];
        right[len - 1] = height[len - 1];
        for (int i = 1; i < len; i++) {
            left[i] = Math.max(height[i], left[i - 1]);
            right[len - i - 1] = Math.max(right[len - i], height[len - i - 1]);
        }
        /*
         * left   0,1,1,2,2,2,2,3,3,3,3,3
         * right  3,3,3,3,3,3,3,3,2,2,2,1
         * height 0,1,0,2,1,0,1,3,2,1,2,1
         */
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            cnt += Math.min(left[i], right[i]) - height[i];
        }
        return cnt;
    }

    /** 对上面方法进行优化，只扫描一遍，利用双指针，边扫描边计算
     * 执行用时 :1 ms, 99.98%
     * 内存消耗 :43.8 MB, 5.02%
     */
    public int trap1(int[] height) {
        if (height == null || height.length == 0)
            return 0;
        int len = height.length;
        int cnt = 0;
        int leftMax = 0, rightMax = 0;
        int left = 0, right = len - 1;
        // 上面方法i从0扫描至len-1， 对每一个i可以接的雨水都进行了计算
        // 本方法扫描时，左右同时扫描，初始left在最左侧，right在最右侧
        // 当left == right时，所有位置都进行了计算。
        // 对于每一个位置来说，计算可以接收的雨水只和较小值有关。
        while (left < right) {
            leftMax = Math.max(height[left], leftMax);
            rightMax = Math.max(rightMax, height[right]);
            if (leftMax < rightMax)
                cnt += leftMax - height[left++];
            else
                cnt += rightMax - height[right--];
        }
        return cnt;
    }
}
```
