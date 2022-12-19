### 解题思路
前指针始终指向当前合法的元素，后指针遍历到某个元素时判断判断前指针覆盖的部分是否已经有两个相同的该元素了，如果没有则赋值。

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        int l = nums.length;
        int left  = 0 ;
        int right = 1;
        while(right < l){
            if(left==0||nums[left-1] != nums[right]){
                nums[left+1] = nums[right];
                left ++;
                right++;
            }
            else{
                right++;
            }
        }
        return left +1;
    }
}
```