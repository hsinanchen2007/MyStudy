### 解题思路
也是贪心解法。只是在排序的时候顺便把元素和求出来。使用冒泡排序，将每趟排序好的那个元素（最后一个元素）相加。然后从数组最后一个元素开始获取。

### 代码

```java
import java.util.List;
import java.util.ArrayList;
class Solution {
    public List<Integer> minSubsequence(int[] nums) {
        List<Integer> list = new ArrayList<>();
        if(nums == null || nums.length == 0)
            return list;
        int sum = 0;// 数组元素和
        //冒泡排序
        for(int i = 1; i < nums.length; i++){
            int j;
            for(j = 0; j < nums.length-i; j++){
                if(nums[j] > nums[j+1]){
                    int temp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = temp;
                }
            }
            sum += nums[j];//得到排序元素的和
        }
        sum += nums[0];//加上缺掉的首元素

        //获取最大子序列
        int temp = 0;
        for(int i = nums.length-1; i >= 0; i--){
            sum -= nums[i];
            temp += nums[i];
            list.add(nums[i]);
            if(temp > sum)
                break;
        }

        return list;
    }
}
```