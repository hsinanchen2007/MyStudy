### 解题思路
两个指针分别在首位和末尾，在首位的指针不断向后移动，如果遇到当前值等于 val，则从末尾找一个不等于 val的数进行替换，直到两个指针相遇。
因为最后只看返回长度范围内的值，所以数组在末尾指针后边的元素可以不关心了，就返回末尾指针的位置即可。

这个方法只要遍历 n个元素即可，但是在一些边界情况，nums 长度为 0或者 1，还有前指针和末尾指针重合的时候容易出现一下问题，需要特殊处理。

### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        if(nums.length == 0) {
            return 0;
        }
        if(nums.length == 1) {
            return nums[0]!=val ? 1 : 0;
        }
        int i = 0;
        int j = nums.length-1;

        while(i < j) {
            if(nums[i] == val) {
                //如果末尾的数和 val相等则向前移动一位，直到找到不是 val的数
                while(i < j && nums[j] == val) {
                    j--;
                }
                if(i < j) {
                    nums[i] = nums[j];
                    j--;
                }


            }
            i++;
        }

        return nums[j]==val ? j : j+1;
    }
}
```