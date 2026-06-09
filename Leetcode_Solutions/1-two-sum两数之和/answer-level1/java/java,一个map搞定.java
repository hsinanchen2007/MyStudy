### 解题思路
![image.png](https://pic.leetcode-cn.com/75203d51317236a2e3b67eb0dd13bbdfd79642d6e09b2b5e13631c9f0bdecdf7-image.png)
### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        //一层for循环 创建hashmap 先假定map中的元素是存在的。将target与a[i]的差值存入map中
        int [] res = new int[2] ;
        Map<Integer, Integer> hash =  new HashMap();
        for(int i = 0 ;i<nums.length;i++){
            int dif = target-nums[i];
            if(hash.containsKey(dif)) {
                res[0] = i ;
                res[1] =  hash.get(dif); //拿到下标
                return res ;
            }
            hash.put(nums[i] , i); //i是下标 target-a[i]是键值
        }
        return res ;
    }
}
```