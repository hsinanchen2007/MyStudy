### 解题思路
先判断数组长度，若为0-2，都将其长度返回
大于2时，从2开始遍历，一个指针一直进行j+1操作
另一个指针也从2开始，开始判断i以及i-1是否与j相同
若相同则表明相同元素已达三个，即i不变，j+1
若存在不同则说明，未到3个相同元素。即赋值
### 代码

```java
class Solution {
    public  int removeDuplicates(int[] nums) {
        if (nums.length == 0) return 0;
        if (nums.length<=2)return nums.length;
        int i = 1;
        for (int j = 2; j < nums.length; j++) {
            if (nums[j] != nums[i]||nums[i-1]!=nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }

}
```