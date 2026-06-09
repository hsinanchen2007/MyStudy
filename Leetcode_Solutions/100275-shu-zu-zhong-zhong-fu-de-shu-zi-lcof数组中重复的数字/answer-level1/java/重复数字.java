### 解题思路
此处撰写解题思路
创建一个新的数组，默认值为0.
将nums数组的值作为arr数组的下标。当有重复的数字时，arr数组中就会出现大于1的。此时抛出该下标即为重复数字
### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        int[] arr = new int[nums.length];
        for(int j=0;j<arr.length;j++){
            arr[nums[j]]++;
            if(arr[nums[j]]>1){
                return nums[j];
            }
        }
        return -1;
    }
}
```