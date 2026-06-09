时间复杂度仅为`O(N)`的桶排序，主要是以下几个步骤：
1. 统计每个数的频次，将结果存入哈希表。
2. 新建一个桶，将哈希表中每个数插入索引为它的频次的这个桶里。
3. 由于桶的索引是数的频次，越往后面的索引也就意味着频次越高，因此倒着遍历桶，取出最先遍历的k个数就是我们想要的答案。

附上带有详细注释的Java代码
```java
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        int maxTimes = -1;
        //将每个数的频次的统计结果存入哈希表
        for(int num : nums){
            if(!map.containsKey(num)){
                map.put(num, 1);
            }else{
                map.put(num, map.get(num) + 1);
            }
            maxTimes = map.get(num) > maxTimes ? map.get(num) : maxTimes;
        }
        //需要注意的是：这里new的只是一个引用变量数组，它们初始化是指向null的
        ArrayList<Integer>[] buckets = new ArrayList[maxTimes + 1];
        //将每个数插入索引为它的频次的那个桶里
        for(int num : map.keySet()){
            int frequency = map.get(num);
            if(buckets[frequency] == null){
                buckets[frequency] = new ArrayList<>();
            }
            buckets[frequency].add(num);
        }
        //由于桶的索引的含义是数出现的频次，越在数组后面的频次就越高
        //想要求出频次最高的k个数，只需要倒着遍历桶即可
        //这里做的是将倒着遍历到的k个数放入要作为结果返回的List中
        List<Integer> result = new ArrayList<>();
        for(int i = maxTimes; i >= 0 && k > 0; i--){
            if(buckets[i] != null){
                //桶的索引的含义是数的频次，因此一个桶里可能有多个数
                for(int num : buckets[i]){
                    if(k > 0){
                        k--;
                        result.add(num);
                    }else{
                        break;
                    }
                }
            }
        }
        return result;
    }
}
```