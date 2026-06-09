感觉不是特别好，借用了额外空间，仅供参考

    时间复杂度O(n)
    空间复杂度O(n)

    使用HashSet保存出现的值，并记录其中的最大值，则结果是1至max+1的范围，
    再进行一次遍历，如果 set中没有得到结果并跳出循环。

```Java
class Solution {
    public int firstMissingPositive(int[] nums) {
        Set<Integer> set = new HashSet<>();
        long max = 1;
        int res = 1;

        for(int i = 0; i < nums.length; i++){
            if(max < nums[i]) max = nums[i];
            set.add(nums[i]);
        }

        for(int i = 1; i <= max + 1; i++){
            if(!set.contains(i)){
                res = i;
                break;
            }
        }

        return res;
    }
}
```
