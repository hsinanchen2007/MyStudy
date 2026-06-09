### 解题思路
先对数组进行排序，然后再for循环，循环到当前元素等于下一个元素的时候，就说明找到重复元素了

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        Arrays.sort(nums);
        Integer value = 0;
        for(int i = 0; i < nums.length; i++){
            value = nums[i];
            if(value ==nums[i + 1]){
                break;
            }
        }
        return value;
    }
}
```