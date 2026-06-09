首先想到前缀和，直接计算并统计结果划分O(n2)的时间复杂度。
```
前缀和数组为sum[];
满足条件的区间和为：
lower <= sum[i] - sum[j] <= upper;
将上述式子变形得到：
sum[i] - upper <= sum[j] <= sum[i] - lower;
也就是说在前缀和数组sum[0...i]中，满足上述条件的sum[j]都对应着一个满足条件的区间;
```
TreeMap底层实现为红黑树，是一种有序映射，查找时间复杂度为O(logN),并且可方便的进行区间查找
由于每次查找都是在sum[0...i]的范围内，所以可以边计算前缀和边插入TreeMap，同时统计满足条件的区间个数
```
class Solution {
    public int countRangeSum(int[] nums, int lower, int upper) {
        if(nums ==  null || nums.length == 0){
            return 0;
        }
        //键值为区间和和这个区间和出现的次数
        TreeMap<Long, Integer> tree = new TreeMap<>();
        tree.put(0L, 1);
        
        int count = 0;
        long sum = 0L;
        for(int num : nums){
            sum += num;
            //subMap()返回一个值在sum - upper 和sum - lower 之间的子集合，values()方法获得这个映射的值得视图
            for(int cnt : tree.subMap(sum - upper, true, sum - lower, true).values()){
                count += cnt; //统计满足条件的区间和个数
            }
            tree.put(sum, tree.getOrDefault(sum, 0) + 1);
        }
        return count;
    }
}
```

