### 解题思路
应用较为灵活地双指针法，慢指针表示该数组中没有重复的元素的长度，快指针作为遍历的条件。
### 代码
```java
class Solution {
    public int removeDuplicates(int[] nums) {
        //数组中没有元素
        if(nums == null || nums.length == 0) return 0;
    
        //双指针中的慢指针
        int i = 0;

        //快指针遍历该数组
        for(int j = i; j < nums.length; j++){
            if(nums[i] != nums[j]){
                //当前两个元素不相等
                //当数组中的元素都不重复时，防止每次都进行复制操作
                if(j - i < 1){
                    nums[i] = nums[j];
                }
                i++;
                nums[i] = nums[j];
            }
        }
        //因为初始指向下标0，因此长度最后需要加1
        return i + 1;
    }
}
```