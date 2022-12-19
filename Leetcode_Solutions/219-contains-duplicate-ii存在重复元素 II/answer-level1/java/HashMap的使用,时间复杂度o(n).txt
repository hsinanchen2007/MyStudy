### 解题思路
这里使用了hashmap,并不需要随数组 进行排序  
利用啊HashMap的特性--key相同就用新value覆盖掉旧的value

[有兴趣的有伙伴可以去学习一下HashMap](https://pic.leetcode-cn.com/688c82cd51360b726262a572c25a191518280ef065cfdf9617df570535e5c69e)
### 代码
```java
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer,Integer> hm = new HashMap<>();
        int len = nums.length;
        for (int i = 0; i < len; i++) {
            if (hm.containsKey(nums[i])) {
               if((i - hm.get(nums[i])) <= k){
                   return true;
               } else{
                   //绝对值大于就覆盖
                   hm.put(nums[i], i);
               }
            } else {
                //不存在就存进去
                hm.put(nums[i], i);
            }
        }
        return false;
    }
}
```