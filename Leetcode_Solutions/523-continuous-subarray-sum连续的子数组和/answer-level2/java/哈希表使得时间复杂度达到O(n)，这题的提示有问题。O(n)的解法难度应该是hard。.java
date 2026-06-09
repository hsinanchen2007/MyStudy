先说一个O(n^2)复杂度的。

若使用一个数组dp[]来记录前n项的和，也就是说dp[i] = nums[0] + nums[1] + ... + nums[i]。

那么对于任意两个下标i,j，可以一次运算求出i，j之间元素和为：

sum(i,j) = nums[i] + nums[i+1] + ... +nums[j-1] + nums[j]
= dp[j] - dp[i] + nums[i]。
这样求出所有j-i >= 2的下标之间的元素和，比较是否是k的倍数即可。

由于这样的元素和有n^2规模个，因此复杂度为O(n^2)

那么如何优化至O(n)呢？

**我们这样考虑，对于数num1,num2可以表示为
num1 = n1*k + m1 ，num2 = n2*k + m2**

****上面的全是整数。
若m1 == m2，假设num2 >= num1 
那么(num2 - num1) % k = (n2*k - n1 *k) % k = 0。****

因此：

遍历这个数组。

使用sum来记录累加到当前位置的和，用一个哈希表来记录temp = sum%k第一次出现的位置。

并且计算当前的 sum%k ,若哈希表中已经存在且两次位置差大于等于2，则找到解，返回true。

但是上面不包含的情况有：
1、连续的两个0，这也是合法解。
2、sum本身是k的倍数，即sum % k == 0，在sum累加的元素数量大于1的时候(也就是至少访问第二个元素时才行)

java ac代码：

```
class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        
        if(nums.length < 2)
            return false;
        
        int sum = 0;
       
        k = k > 0 ? k : -k;
        
        HashMap<Integer,Integer> map = new HashMap();
        
        for(int i = 0;i < nums.length;i++)
        {
            sum += nums[i];
            int temp = sum;
            if(k != 0){
            
            if(sum % k == 0 && i > 0)
               return true;
                
              temp = sum % k;
            }
            if(!map.containsKey(temp))
                map.put(temp,i);
            else if(map.get(temp)+2 <= i)
                return true;
                
            
            
        }
        for(int i = 1;i < nums.length;i++)
            if(nums[i-1] == 0 && nums[i] == 0)
                return true;
        
        
        return false;
        
    }
}
```







