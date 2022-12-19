### 解题思路
1.当遍历指针所指的元素值变换时，赋值指针移动并修改数组中的值，就这么简单
2.过滤条件：当输入为空数组时，直接return0
### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums.length==0){
            return 0;
        }
        int count = 0 , element = nums[0];
        for ( int a : nums  ) {
            if (a!=element){
                element = a ;
                nums[++count] = a ;
            }
        }
        return ++count;
    }
}
```