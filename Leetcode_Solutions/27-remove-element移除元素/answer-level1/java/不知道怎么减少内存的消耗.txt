### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int pos = 0;
        int length = nums.length;
        for(int element : nums){
            if(element != val){
                nums[pos] = element;
                pos += 1;
            }
            else{
                length --;
            }
        }
        return length;

    }
}
```