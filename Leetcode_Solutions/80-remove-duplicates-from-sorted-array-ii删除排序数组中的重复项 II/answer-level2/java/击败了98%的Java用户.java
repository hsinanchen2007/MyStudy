## 题目解析
用一个标识curPos记录当前结尾的位置。
    如果遍历到的数nums[i]和nums[curPos-1]相等。说明nums[i]==nums[curPos]==nums[curPos-1]。
    因此已经连续三个数相等了。nums[i]直接忽略即可。
    如果nums[i]和nums[curPos-1]不相等。则应将其赋值到curPos+1的位置。
    遍历结束以后。curPos+1就是需要求的新长度。
## 代码
```java
public int removeDuplicates(int[] nums) {
        if(nums.length < 3){
            return nums.length;
        }
        int curPos = 1;
        for (int i = 2; i < nums.length ; i++) {
            if(nums[i] != nums[curPos-1]){
                nums[++curPos] = nums[i];
            }

        }

        return curPos+1;
    }
```
# [更多leetcode题解写在本人博客](http://51leetcode.top/tags?tag=leetcode)