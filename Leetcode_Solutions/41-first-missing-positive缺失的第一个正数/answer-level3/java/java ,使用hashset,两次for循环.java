### 解题思路
先将非零正整存到hashset当中,然后for循环从小到大去hashset中去检查是否存在.
![aaa.png](https://pic.leetcode-cn.com/30f5a7868b7da479bd941235bb0d5c88e482c2c3818cd0fbeebf9d9b55b988f9-aaa.png)

### 代码

```java
class Solution {
    public int firstMissingPositive(int[] nums) {
        HashSet<Integer> set =new HashSet<Integer>();
        for(int i=0;i<nums.length;i++){
            if(nums[i]>0){
                set.add(nums[i]);//将正整数放在hashset当中(set为集合)
            }
        }
        for(int j=1;j<Integer.MAX_VALUE;j++){//遍历正整数(从一开始)
            if(!set.isEmpty()&&set.contains(j)){
                continue;
            } else {
                return j;
            }                
        }
        return 1;
    }
}
```