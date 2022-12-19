### 结果
1ms
### 解题思路
1. 从后往前遍历，存储当前最大值
2. 当值大于等于max时，排序，并记录max
3. 当值小于max时，找到第一个比该值大的数（因为后半段数组已经排好序），然后交换。
4. 结束

### 代码

```java
class Solution {
    public void nextPermutation(int[] nums) {
        int max = Integer.MIN_VALUE;
        for(int i = nums.length-1 ; i >= 0; i--){
            int index = 0;
            if(max > nums[i]){  //当该值小于max时，说明下一更大的排列存在
                index = i;
                int temp = nums[i];
                while(index < nums.length-1 && nums[++index] <= temp);  //需要交换值则为往后遍历第一个比它大的数
                nums[i] = nums[index]; //交换，然后结束
                nums[index] = temp;
                break;
            }else if(nums[i] >= max){ //当该着大于max时，排序
                max = nums[i];
                index = i;
                int num = nums[index];
                while(index < nums.length-1 && nums[index] <= num){
                    nums[index] = nums[index+1];
                    index++;
                }
                nums[index] = num;
            }
        }
    }
}
```