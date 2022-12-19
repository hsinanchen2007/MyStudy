### 解题思路
1.从后向前搜索高位数小于低位数的index，若没有，则直接对数组重新排序；
2.存在高位数小于低位数则说明存在序列大于当前序列，然后从后向前检索大于该数值的最小值，然后两者交换位置；
3.对index-1之后的有序数组进行排序，前后依次交换即可。

### 代码

```java
class Solution {
    public void nextPermutation(int[] nums) {
        int i = 0;
        for(i = nums.length - 1; i > 0; i--){
            if(nums[i] > nums[i-1]){
                int l,r;
                for(r = nums.length -1; r > i - 1; r--){
                    if(nums[r] > nums[i-1]){
                        int temp = nums[i-1];
                        nums[i-1] = nums[r];
                        nums[r] = temp;
                        break;
                    }
                }
                for(l = i, r = nums.length - 1;l < r; l++,r-- ){
                    int temp =nums[r];
                    nums[r] = nums[l];
                    nums[l] = temp;
                }
                break;
            }
        }
        if(i==0){
            Arrays.sort(nums);
        }
    }
}
```