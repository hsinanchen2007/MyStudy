### 解题思路

一共遍历两次数组

第一次遍历: 将所有重复两次以上的元素替换成Integer.MAX_VALUE

   如：将 [1,1,1,2,2,2,3] 替换成 [1,1,Integer.MAX_VALUE,2,2,Integer.MAX_VALUE,3]
第二次遍历: 再将后面的元素前移。

   如： 将[1,1,Integer.MAX_VALUE,2,2,Integer.MAX_VALUE,3] 
   转换成 [1,1,2,2,3,Integer.MAX_VALUE,Integer.MAX_VALUE]

只遍历了两次所以时间复杂度是O(N)   

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums == null) return 0;
        int len = nums.length;
        if (len <= 1) return len;
        boolean flag = true;  // flag 用于判断是否有必要进行第二次操作
        // 第一次遍历
        for (int i = 0; i < len; ) {
            int curr = nums[i];
            int p = i + 1;
            if (p < len && nums[p] == curr) {
                p++;  // 找到第三个不重复的元素，将它和后续的替换
                while (p < len && nums[p] == curr) {
                    nums[p] = Integer.MAX_VALUE;
                    p++;
                    flag = false;  // 有格子被赋值成了Integer.MAX_VALUE，则将flag置为flase
                }
            }
            i = p;
        }
        if (flag) return len; // 仍为true则跳过第二次遍历
        // 第二次遍历
        int slow = 2;
        while (nums[slow] != Integer.MAX_VALUE) {
            slow++;  // 找到开始进行元素前移的位置，从第一个Integer.MAX_VALUE开始
        }
        for (int fast = slow; fast < len; fast++) {
            // fast 用来找需要前移的值
            if (nums[fast] != Integer.MAX_VALUE) {
                while (nums[slow] != Integer.MAX_VALUE) {
                    slow++; // 而slow总是指向 Integer.MAX_VALUE
                }
                nums[slow] = nums[fast];
                nums[fast] = Integer.MAX_VALUE;
                slow++;
            }
        }
        return slow;
    }
}
```