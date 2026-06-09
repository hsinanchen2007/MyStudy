### 解题思路
先定义一个元素标记flag，再定义一个元素重复次数repeatNum,循环遍历数组，如果与标记元素flag相同就计数（注意初始要是-1），否则更新标记元素，同时移位数组元素覆盖重复元素（移位数等于重复数）
![运行.jpg](https://pic.leetcode-cn.com/00a3dda0eda769201a20b5e30a128843f698994d08de7b8a28599a135e64878e-%E8%BF%90%E8%A1%8C.jpg)

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums == null || nums.length == 0){
            return 0;
        }
        int flag = nums[0];
        int repeatNum = -1;
        for(int i = 0; i < nums.length; i++){
            if(nums[i] == flag){
                repeatNum++;
            }else {
                flag = nums[i];
                nums[i-repeatNum] = nums[i];
            }
        }
        return nums.length - repeatNum;
    }
}
```