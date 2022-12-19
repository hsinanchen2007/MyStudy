```java
class Solution {
    public int maxProduct(int[] nums) {
        int[] dp=new int[nums.length];
        dp[0]=nums[0];
        int max=dp[0];
        for(int i=1;i<nums.length;i++){
            int s1=nums[i];
            int s2=s1;
            for(int j=i-1;j>=0;--j){
                s1=s1*nums[j];
                if(s1>s2)
                    s2=s1;
            }
            dp[i]=Math.max(s2,nums[i]);
            max=Math.max(max,dp[i]);
```javascript []
console.log('Hello world!')
```
```python []
print('Hello world!')
```
```ruby []
puts 'Hello world!'
```
        }
        return max;
    }
}