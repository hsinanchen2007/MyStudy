本题与560 和为k的子数组类似，都是采取前缀和的方法去处理，本题也是**子数组要求连续**，同时不要求值等于几，而是要求奇数的个数，那就把奇数置为1，偶数置为0，转换为求解和为K的子数组个数。
```java
class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        /*使用前缀和的原因也是子数组要连续
        使用前缀和（将奇数变为1，偶数为0）
        sum[i] = sum[i-1]+num;
        如果存在sum[i]-k>0,那就说明肯定存在一段数组的和等于k
        假设从（j,n]的和为k ,那么当我们找到sum[n]的时候，就会存在sum[n]-k=sum[j],此时times就加上sum[j]的个数，因为这里j可能不是一个值
        */
        Map<Integer,Integer>map = new HashMap<>();
       int sum = 0;
        map.put(0,1);
        int temp = 0;
        for(int i=0;i<nums.length;i++)
        {
            if(nums[i]%2!=0)
            {
                sum += 1;
                }
            if(sum>=k)
            {
                //和为j
                int j = sum-k;
                //找和为j的个数
                temp+=map.get(j);
            }
            map.put(sum,map.getOrDefault(sum,0)+1);
        }
        return temp;
    }
}
```
