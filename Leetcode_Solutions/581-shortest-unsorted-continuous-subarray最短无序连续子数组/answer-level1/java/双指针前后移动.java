### 解题思路

***从右往左移动:*** 首先初始化最小值为数组最后一个值，初始化 `minIndex` 为-1(`minIndex` 表示从右往左开始出现升序的元素索引)。将当前元素与最小值比较。若当前值小于最小值，则更新最小值。若当前值大于等于最小值(**注意：若相等，依然需要往左移，因为要求最短数组**))，则更新 `minIndex` 为当前元素的索引  
***从左往右移动:*** 同上。从左往右依此遍历元素，将当前元素值与最大值比较。若当前值大于最小值。则更新 `max` 的值。若当前值小于等于最大值，则更新 `maxIndex` 为当前元素的索引
**时间复杂度：$O(n)$, 最坏的情况遍历整个列表**
**空间复杂度: $O(1)$, 只开辟了2个指针**
### 代码

```java
class Solution {
     // 最短无序子数组
    public int findUnsortedSubarray(int[] nums){
        if(nums == null | nums.length < 2){
            return 0;
        }

        int min = nums[nums.length - 1];// 初始化右侧最小值为数组最后的一个值
        int minIndex = -1;
        // 从右往左依此遍历元素，将当前元素与最小值比较。若当前值小于最小值，则更新最小值。若当前值大于等于最小值，则更新 minIndex 为当前元素的索引
        for(int i = nums.length - 2; i != -1; i--){
            if(nums[i] <= min){
                min = nums[i];
            } else{
                minIndex = i;
            }
        }
        if(minIndex == -1) return 0;

        int max = nums[0]; // 初始化左侧最大值为第一个元素
        int maxIndex = 0;
        // 从左往右依此遍历元素，将当前元素值与最大值比较。若当前值大于最小值。则更新 max 的值。若当前值小于等于最大值，则更新 maxIndex为当前元素的索引
        for(int i = 0; i<= nums.length - 1; i++){
            if(nums[i] >= max){
                max = nums[i];
            } else{
                maxIndex = i;
            }
        }
        // return minIndex - maxIndex +1;
        return maxIndex - minIndex + 1;

    }
}
```