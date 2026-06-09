### 解题思路

菜鸟如我想到这个问题大概可以通过3次翻转实现，相信大家肯定知道了

写了3次，我个人觉得这里面有点要注意的地方：

1. 如果 k == N * nums.length ，则我们什么也不需要做，直接return ，其中 N >= 0      
2. 如果 k > nums.length ,那它的效果和  k = k % nums.length 的效果是一致的

剩下的就是写代码了，很简单

### 代码

```java
class Solution {
    public void rotate(int[] nums, int k) {
        if(nums == null){return;}

        int numsLen = nums.length;

        if(k >= numsLen){
            if(k % numsLen == 0){
                return;
            }
            k = k % numsLen;
        }

        reverse(nums,0,numsLen - 1);
        reverse(nums,0,k-1);
        reverse(nums,k,numsLen - 1);
    }

    private void reverse(int[] nums,int start,int end){
        int i = start;
        int j = end;
        while(i<j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i ++;
            j --;
        }
    }
}
```