### 解题思路
这种比较大小的问题首先应该想到排序  
其次需要统计个数 故使用桶排序
### 代码

```java
import java.util.Arrays;
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        //使用桶排序  0-100 101个数
        int[] array = new int[101];
        int[] res = new int[nums.length];
        int count = 0;
        //统计每个数字的个数
        for(int i = 0 ; i < nums.length; i++){
            array[nums[i]]++;
        }
        //累加这个数字之前的数字 就是比他小的数据
        for(int j = 0; j < nums.length; j++){
             for(int k =0; k< nums[j];k++){
                count += array[k];
             }
             res[j] = count;
             count = 0;
        }
        return res;
    }
}
```