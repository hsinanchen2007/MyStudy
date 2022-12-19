设定两个指针，一个指向开头，一个指向末尾。
过程：利用右指针始终比左指针大的特性，循环数组计算两指针的间隙。比较数组的时候，根据两指针的索引在数组中的大小判定，即谁小谁前进。一直到找到最大的值为止，计算盛最多水的容器，也就是算正方形的面积（底*高），两指针的距离*数组中最小的值
```
    public int maxArea(int[] height) {
        // 当给定个数小于等于1的时候返回0
        if (height == null || height.length <= 1) {
            return 0;
        }
        int maxArea = 0;
        int i = 0;
        int length = height.length - 1;
        while (i < length) {
            int tempArea = Math.min(height[i], height[length]);
            tempArea = tempArea * (length - i);
            maxArea = Math.max(maxArea, tempArea);
            // 比较数组中，两个的值，谁小谁前进
            if (height[i] < height[length]) {
                i++;
            } else {
                length--;
            }
        }
        return maxArea;
    }
```
