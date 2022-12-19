该题直观来看是寻找拥有和`nums`本身有相同的度且长度最短的连续子数组。首先题目描述给了度的解释：指数组里任一元素出现频数的最大值。
知道了度的概念，我们首先可以想到找到出现频次最大的数只需一次遍历就可以完成，假设该数为`num`，而和`nums`有相同度的连续子数组中长度最小的自然是以`num`开始及结尾的子数组。这点想明白后我们知道为了得到该子数组的长度，只需要知道`num`的起始索引及结束索引即可，在遍历的过程中对索引进行记录，这样我们便可以在O(n)的时间内完成。
有一点需要注意，那就是有可能存在多个相同的数，它们的出现频次一样，在这种情况下找最小长度的连续子数组时需要对比包含这几个数的子数组长度，因此我们需要保存多个索引，使用的数据结构自然想到的便是Map，但由于题目描述中给出了`nums`中数字的范围[0, 500000)，因此我们可以用数组来代替Map，减少内存消耗。
```
class Solution {
    public int findShortestSubArray(int[] nums) {
        if(nums == null || nums.length == 0) {
            return 0;
        }
        //使用Array代替Map
        int[] counts = new int[50000];
        int[] indexs = new int[50000];
        for(int i = 0; i < 50000; i++) {
            indexs[i] = -1;
        }
        int maxCount = 0;
        int maxCountNum = 0;
        int endIndex = 0;
        int num;
        for(int i = 0; i < nums.length; i++) {
            num = nums[i];
            counts[num] = counts[num] + 1;
            if(indexs[num] == -1) {
                indexs[num] = i;
            }
            if(maxCount < counts[num]) {
                maxCount = counts[num];
                endIndex = i;
                maxCountNum = num;
            } else if(maxCount == counts[num]) {
                if(i - indexs[num] < endIndex - indexs[maxCountNum]) {
                    endIndex = i;
                    maxCountNum = num;
                }
            }
        }
        return endIndex - indexs[maxCountNum] + 1;
    }
}
```
