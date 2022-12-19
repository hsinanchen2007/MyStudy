### 解题思路
类似于count sort的思想，因为输入的值有范围，所以建立一个长度为(nums.length + 1)的counting数组，记每个数字出现的次数，再返回count[i] == 0 以及 count[j] == 2的i，j即可。

### 代码

```java
class Solution {
    public int[] findErrorNums(int[] nums) {
        int[] count = new int[nums.length + 1];
        for(int i = 0; i < nums.length; i++){
            count[nums[i]]++;
        }
        int deplicated = 0, missed = 0;
        for(int i = 1; i < count.length; i++){
            if(count[i] == 2)
                deplicated = i;
            if(count[i] == 0)
                missed = i;
            if(missed != 0 && deplicated != 0)
                break;
        }
        return new int[]{deplicated, missed};
    }
}
```