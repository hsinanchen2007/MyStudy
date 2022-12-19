执行结果：
通过
显示详情
执行用时 :
1 ms
, 在所有 Java 提交中击败了
99.78%
的用户
内存消耗 :
41.6 MB
, 在所有 Java 提交中击败了
33.61%
的用户
```
class Solution {
    public int singleNumber(int[] nums) {
        int sum=0;
        for(int i=0; i<nums.length; i++){
            sum^=nums[i];
        }
        return sum;
    }
    
}
```
