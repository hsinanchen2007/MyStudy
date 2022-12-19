### 解题思路
这一题主要是使用了快慢指针的算法。
如果对时间复杂度没有过多的要求，那么这题也是比较容易，可以使用Set进行一个输出和重新赋值。
快慢指针的思想就是使用两个指针slow和fast，步骤为：

- 当slow和fast指向的数据相同时，fast++,向前寻找与slow不同的项
- 当slow的fast指向的的数据不同时，先让slow++，指向一个是fast或者和fast数据相同的项，而后将fast当前指向的数据赋值给slow，fast++,继续向前寻找

这一题的任务是去重，慢指针的任务是收集不重复的数据，快指针的任务的是向前寻找和当前慢指针不同的数据，而后将其归入到慢指针的数据集中。

可看一下理解的视频：[点击观看](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/solution/shi-ping-dong-hua-jie-xi-bao-ni-dong-by-novice2mas/)

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        //快慢指针
        if(nums == null || nums.length == 0){
            return 0;
        }    
        int slow = 0,fast = 0;

        while(fast < nums.length){
            if(nums[slow] != nums[fast]){
                slow++;
                nums[slow] = nums[fast];
                fast++;
            }else if(nums[slow] == nums[fast]){
                fast++;
            }
        }

        return slow+1;
    }
}
```