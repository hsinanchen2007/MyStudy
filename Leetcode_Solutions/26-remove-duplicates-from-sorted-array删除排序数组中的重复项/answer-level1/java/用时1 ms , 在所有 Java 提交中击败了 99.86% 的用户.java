### 解题思路
定义一个计数器和一个指针。然后遍历数组中和start指向的值不同的值。这里要考虑两种情况
1. start和i指向的两个值中间有其他的数 这时我们需要让start++并把i指向的值赋给start指向的值然后再让计数器加一
2. start和i指向的两个值中间没有其他的数，这时我们直接让计数器加一就行

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        int start=0,bt=1;
        for (int i=1;i<nums.length;i++) {
            if(nums[start]!=nums[i]){
                if(++start!=i)
                    nums[start] = nums[i];
                bt++;
            }
        }
        return bt;
    }
}
```