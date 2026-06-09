### 解题思路
类似于插入排序，不用借助其他的数据结构，
空间复杂度为O（1），时间复杂度为O（N^2）

### 代码

```java
class Solution {
    public int[] exchange(int[] nums) {
        int n = nums.length;
        if(n == 1){
            return nums;
        }
        for(int i = 1; i < n; i++){
            //相当于前面那个空格，用来交换的
            int temp = nums[i];
            if(nums[i] % 2 == 1){
                int j = i;
                //当j前面有偶数时，偶数往后移一位
                while(j >= 1 && nums[j - 1] % 2 == 0){
                    nums[j] = nums[j - 1];
                    j--;
                }
                //当不为偶数时，此时坐标上的数字改为i
                nums[j] = temp;
            }
        }
        return nums;
    }
}
```