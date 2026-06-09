### 解题思路
1.用count[]数组记录索引，初始化为-1，为了方便从0开始引用下标；
2.统计各个元素出现的次数；
3.计算每个元素在排序数组中出现的最高位索引；
4.由高到低依次填入；
5.再复制一遍。

### 代码

```java
class Solution {
    public void sortColors(int[] nums) {
        int[] count = {-1,-1,-1};
        for(int i = 0; i < nums.length; i++) count[nums[i]] += 1;
        for(int j = 1; j < 3; j++) count[j] += count[j-1]+1;
        int[] res = new int[nums.length];
        for(int i = 0; i < nums.length; i++) res[count[nums[i]]--] = nums[i];
        for(int i = 0; i < nums.length; i++) nums[i] = res[i];
    }
}
```