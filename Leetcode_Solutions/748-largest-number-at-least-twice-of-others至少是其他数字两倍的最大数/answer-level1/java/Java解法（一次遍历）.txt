【想法】
    1、经过一次遍历，找到最大和第二大的两个元素的索引
    2、只要最大 > 第二大的二倍，返回最大值的索引，否则返回-1
【复杂度分析】
    时间复杂度：O(N)
    空间复杂度：O(1)
```java
public int dominantIndex(int[] nums) {
        //判断数组长度，若小于2，则返回0
        if (nums.length < 2){
            return 0;
        }
        int maxIndex;
        int secondIndex;
        //定初始第一大和第二大索引值
        if (nums[0] < nums[1]){
            maxIndex = 1;
            secondIndex = 0;
        }else {
            maxIndex = 0;
            secondIndex = 1;
        }
        //经过一次遍历后找到最大值、第二大值的索引
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > nums[maxIndex]){
                secondIndex = maxIndex;
                maxIndex = i;
                continue;
            }
            if (nums[i] < nums[maxIndex] && nums[i] > nums[secondIndex]){
                secondIndex = i;
            }
        }
        return nums[maxIndex] >= nums[secondIndex] * 2 ? maxIndex : -1;
    }
```

希望得到大家的喜欢以及提问！！
