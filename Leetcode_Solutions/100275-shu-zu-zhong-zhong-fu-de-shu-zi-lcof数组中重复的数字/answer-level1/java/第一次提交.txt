### 解题思路

因为数组内数字范围做了限定，i= 0~n-1 和num = 0~n-1。
所以通过将每个数字num，放在对应的i上，每次放置的时候，如果发现目标位置的值已经是num,则该数字重复。
空间复杂度 O(1) - 额外的空间用于交换数字值
时间复杂度 O(N)

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        for(int i=0;i<nums.length;i++){
            int num = nums[i];
            while(num != i){
                int tmp = nums[num];
                if(tmp == num){
                    return num;
                }else{
                    //swap and continue
                    nums[num] = num;
                    nums[i] = tmp;
                    num = tmp;
                }
                
            }
            
        }
        return 0;
    }
}
```