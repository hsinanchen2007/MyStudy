### 解题思路
nums中每两个数为一组，a是奇数位置的数字，b是偶数位置的数字，返回a个b。例如[1,2,3,4]就要返回1个2和3个4

### 代码

```java
class Solution {
    public int[] decompressRLElist(int[] nums) {
        int len = 0;
        for(int i = 0; i < nums.length; i = i + 2){
            len += nums[i];
        }
        int count = 0;
        int [] res = new int[len];
        for(int i = 0; i < nums.length; i = i + 2){
            for(int j = 0; j < nums[i]; j++){
                res[count] = nums[i+1];
                count++;
            }
        }
        return res;
    }
}
```