```java
class Solution {
    public int removeElement(int[] nums, int val) {
        if(nums.length == 0) return 0;
        int i = 0, j = nums.length-1;
        while(i<j){
            while(i<j && nums[i]!=val) i++;
            while(i<j && nums[j]==val) j--;
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        if(nums[i] == val)
            return i;
        else return i+1;
    }
}
```
双指针两头遍历的方法，但是处理起来麻烦很多，涉及很多小陷阱。