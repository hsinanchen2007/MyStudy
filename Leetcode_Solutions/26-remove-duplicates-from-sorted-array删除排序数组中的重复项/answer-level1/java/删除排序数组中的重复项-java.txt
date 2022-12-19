###思路：
 可以使用两个指针（快慢指针）来指示数组中的下标，其中curr指针时用来遍历的，curr指示当前遍历的数组下标，count指示的排除相同元素后的不重复元素的数组下标（当然这里还是在原数组进行操作，只是我们可以看成是一个新数组）。
  当两个指针指示的值相同时，先让count++,指示“新数组”的空位，然后将curr指针指示的值赋予它，遍历的最后，返回count++(这里count指针是下标，而题目让我们返回长度);

###代码示例：
```
class Solution {
    public int removeDuplicates(int[] nums) {
       int curr = 1, count = 0;
       for (curr = 0; curr < nums.length; curr++) {
           if (nums[curr] != nums[count]) {
               count++;
               nums[count] = nums[curr];
           }

       }
       return count + 1;
    }
}
```

时间复杂度：执行时间1ms,打败99.93%的java用户，为O(n);
空间复杂度：消耗41.5MB，打败12.37%的java用户，为O(1);