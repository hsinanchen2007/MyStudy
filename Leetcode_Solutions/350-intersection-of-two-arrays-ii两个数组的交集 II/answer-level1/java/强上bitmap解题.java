![image.png](https://pic.leetcode-cn.com/9deb9dca478be39dd7f79af688f76d88296724d64465cec38e9157a70cf83064-image.png)

解题思路：
1. 找出短数组和长数组
2. 在最短数组中找出最大值和最小值（除0x7fffffff，0x80000000之外的最大值和最小值）；
3. 创建两个int[]：一个用于存放大于等于0的数，一个用于存放小于0的数。

疑问：
 - **为什么找短数组和长数组和最短数组中的最大值和最小值？**
 -- 拿短数组中的最大值和最小值对长数组中的数据进行过滤，就是为了定义并集的有效范围。
 
 - **为什么0x7fffffff，0x80000000做特殊处理？**
 -- 因为这两个数是int的两极。正极其实也可以不用处理，因为new int[0x7fffffff]是有效的；而new int[0x80000000]是无效的，所以必须特殊处理。其实也不是啥特殊处理，看代码就知道了。

 - **为什么用两个bitmap，而不用一个bitmap？**
 -- 因为bitmap带符号的话，bitmap需要用2个bit才能表示一个值（虽然这里的数据量并不多），而这里是只是把有符号的bitmap拆开成了两个，个人觉得会比较清晰，操作方便。

 - **为什么是32？**
 -- Java中的int固定是4个字节，32位。
```
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
       int MaxPositiveNum = 0;
        int MinNum = 0;
        int[] minLenArr;
        int[] maxLenArr;

        if (nums1.length < nums2.length) {
            minLenArr = nums1;
            maxLenArr = nums2;
        } else {
            minLenArr = nums2;
            maxLenArr = nums1;
        }

        for (int value : minLenArr) {
            if (value != Integer.MAX_VALUE && MaxPositiveNum < value) {
                MaxPositiveNum = value;
            }
            if (value != Integer.MIN_VALUE && MinNum > value) {
                MinNum = value;
            }
        }

        int bitmapNegativeSize = MinNum < 0 ? 1 + (0 - (MinNum / 32)) : 1 + MinNum / 32;
        int[] bitmap = new int[1 + MaxPositiveNum / 32];
        int[] bitmapNegative = new int[bitmapNegativeSize];
        int[] duplicatesTemp = new int[maxLenArr.length];
        int tempIndex = 0;

        int MAX_VALUE_COUNT = 0;
        int MIN_VALUE_COUNT = 0;
        int[] countPositive = new int[MaxPositiveNum + 1];
        int[] countNegative = new int[(-MinNum) + 1];

        for (int num : minLenArr) {
            if (num == Integer.MAX_VALUE) {
                MAX_VALUE_COUNT++;
            } else if (num == Integer.MIN_VALUE) {
                MIN_VALUE_COUNT++;
            } else if (num >= 0) {
                if (!exitsPositive(bitmap, num)) positiveAdd(bitmap, num);
                countPositive[num]++;
            } else {
                if (!exitsNegative(bitmapNegative, num)) negativeAdd(bitmapNegative, num);
                countNegative[-num]++;
            }
        }

        for (int num : maxLenArr) {
            if (num == Integer.MAX_VALUE && MAX_VALUE_COUNT > 0) {
                duplicatesTemp[tempIndex++] = num;
                --MAX_VALUE_COUNT;
            } else if (num == Integer.MIN_VALUE && MIN_VALUE_COUNT > 0) {
                duplicatesTemp[tempIndex++] = num;
                --MIN_VALUE_COUNT;
            } else if (num >= 0 && num <= MaxPositiveNum && exitsPositive(bitmap, num) && countPositive[num] > 0) {
                duplicatesTemp[tempIndex++] = num;
                --countPositive[num];
            } else if (num >= MinNum && num < 0 && exitsNegative(bitmapNegative, num) && countNegative[-num] > 0) {
                duplicatesTemp[tempIndex++] = num;
                --countNegative[-num];
            }
        }

        int[] duplicates = new int[tempIndex];
        System.arraycopy(duplicatesTemp, 0, duplicates, 0, tempIndex);
        return duplicates;
    }
    private static void positiveAdd(int[] nums, int positiveNum) {
        int row = positiveNum >> 5;
        nums[row] |= 1 << (positiveNum & 0x1F);
    }

    private static void negativeAdd(int[] nums, int negativeNum) {
        int row = (-negativeNum) >> 5;
        nums[row] |= 3 << (-negativeNum) % 4 * 2;
    }

    private static boolean exitsPositive(int[] nums, int num) {
        int row = num >> 5;
        return (nums[row] & (1 << (num & 0x1F))) != 0;
    }

    private static boolean exitsNegative(int[] nums, int negativeNum) {
        int row = (-negativeNum) >> 5;
        return (nums[row] & (3 << (-negativeNum) % 4 * 2)) != 0;
    }
}
```
