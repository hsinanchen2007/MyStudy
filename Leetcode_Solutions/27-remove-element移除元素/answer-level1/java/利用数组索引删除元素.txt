### 解题思路
此处撰写解题思路
1.遍历数组，如果有等于指定val的元素，把当前位置后面的所有元素向前移动一位
2.由于第一步中后面的所有元素都向前移动了一位，所以当前位置的元素就变成了之前的下一个元素，我这里是把索引先--再++，当然也可以在循环中不++，这里也不--，在if外面++
3.由于第一步中后面的所有元素都向前移动了一位，所以遍历不能再遍历到之前数组的大小了，移动之后相当于数组的长度-1，所以这里使用result作为判断条件，移动之后把result--
### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        if (nums.length == 0) return 0;
        int result = nums.length;
        for (int i = 0; i < result; i++) {
            if (nums[i] == val){
                result--;
                for (int j = i; j < result; j++) {
                    if (j < nums.length - 1) {
                        nums[j] = nums[j + 1];
                    }
                }
                i--;
            }
        }
        return result;
    }
}
```