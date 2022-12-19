### 解题思路
示例：-2  1  -3   4  -1  2  1  -5  4
now： -2  1  -2   4  3   5  6  1   5
res： -2  1   1   4  4   5  6  6   6

now表示当前最大的累加值，now遇到小于0时就重新累加
res表示待返回的结果，res[i]=max(now[i],res[i-1])

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int now=nums[0], res=nums[0];
        for(int i=1;i<nums.length;i++){
            if(now<0){
                now = nums[i];
            }else{
                now = now+nums[i];
            }
            res = Math.max(res,now);
        }
        return res;
    }
}
```