### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
         if (nums.length == 0)
             return 0;
         int number = 0;
         //不适用额外数组空间
         for (int i=0; i < nums.length ; i++) {
            if ( nums[i] != nums[number] ) {
                number++;
                nums[number] = nums[i];
            }
         }
          number+=1; 
          return number;
  }

}
```