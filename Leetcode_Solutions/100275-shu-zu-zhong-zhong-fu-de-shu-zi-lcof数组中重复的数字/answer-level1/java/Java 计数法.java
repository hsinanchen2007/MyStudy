### 解题思路
数组的最大值 n-1 ,数组的长度 n
1. 创建一个数组长度为N记录每个值出现次数（用Set这些太重了）
2. 一边添加一边查找，如果有相同的数出现就返回

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {

        int [] arr = new int[nums.length];

        for(int i = 0; i < nums.length; i++){
            if(arr[nums[i]] >= 1){
                return nums[i];
            } else {
                arr[nums[i]]++;
            }
        }
        return -1;
    }
}
```