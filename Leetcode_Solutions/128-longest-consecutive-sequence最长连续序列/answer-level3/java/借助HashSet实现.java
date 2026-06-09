### 解题思路
1. 借助哈希Set实现
2. 选用HashSet的原因是去重，因为只要有一个值相等就可以了
3. 找到一个数，用这个数作为HashSet的Key，然后找这个数-1作为Key，直到找不到为止
4. 需要明确的是可能会存在负数，所以需要把Key化为Integer来处理

### 代码

```java
class Solution {
    public int longestConsecutive(int[] nums) {
        // 数组如果为0，则直接返回0
        if(nums.length == 0){
            return 0;
        }
        // 将数组的元素初始化到集合
        // 达到了去重到目的
        Set<Integer> set = new HashSet<>();
        for(int e:nums){
            set.add(e);
        }
        // 最长序列至少也是1，因为1个元素也是序列
        int maxLongSize = 1;
        int num;
        // 遍历集合
        for(Integer e: set){
            num = e;
            int longSize = 1;
            // 找num下一个元素是不是在集合中
            // 如果在集合中那么就将最大长度+1
            while(set.contains(--num)){
                longSize++;
                if(longSize > maxLongSize){
                    maxLongSize = longSize;
                }
            }
        }
        return maxLongSize;
    }
}
```