### 解题思路
使用数组记录nums中每个数字出现的次数，既然有重复的数字，说明必定有一个计数为2 一个计数为0

### 代码

```java
class Solution {
    public int[] findErrorNums(int[] nums) {
        int[] count = new int[nums.length];
        int[] res = new int[2];
        for(int n : nums){
            count[n - 1]++;
        }
        for(int c = 0; c < count.length; c++){
            if(count[c] == 0){
                res[1] = c + 1;
            }else if(count[c] == 2){
                res[0] = c + 1;
            }
        }
        return res;
    }
}
```