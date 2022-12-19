### 解题思路
思路全在代码里

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        int size = 1;
        int top = nums[0];
        for(int i = 1;i<nums.length;i++){
            if(size == 0){
                top = nums[i];
                size++;
            }
            else if(top == nums[i])
                size++;
            else{
                size--;
            }
        }
        return top;
    }
}
```