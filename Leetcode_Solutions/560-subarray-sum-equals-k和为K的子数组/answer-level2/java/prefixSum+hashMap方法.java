### 解题思路
具体思路：
原本求从0~nums.length共多少个组合使得和为k
现令0~i和为sum 即 sum = nums[0]+....+nums[i]
寻找有多少个0~j之和 即 nums[0]+....+nums[j]==sum-k
  即可求 i~j 之间有多少组合的和为k
以[1,1,-1,1] k=2为例
![QQ图.jpg](https://pic.leetcode-cn.com/9019ef8fb5584418ee38714afd6fe9af218232e97565ea470b6523d99fe40ce5-QQ%E5%9B%BE.jpg)

### 代码

```java
class Solution {
    public int subarraySum(int[] nums, int k) {
        int n=nums.length;
        Map<Integer, Integer> map=new HashMap<>();
        map.put(0,1);//0出现了1次
        int sum=0;
        int res=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(map.containsKey(sum-k)){
                res+=map.get(sum-k);
            }
            map.put(sum,map.getOrDefault(sum,0)+1);
        }
        return res;
    }
}
```