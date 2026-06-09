本题和[leetcode347. 前k个高频元素](https://leetcode-cn.com/problems/top-k-frequent-elements/)实际上是一个类型的，都可以利用桶排序来高效解决。

大概是这么几个步骤：

1. 遍历字符数组，将每个字符的和它对应的频次存入哈希表中。
2. 新建一个桶，将每个字符存入索引为它的频次的那个桶中。由于桶的索引本身就是自增的，因此这样就直接利用桶完成了对每个字符按照它的出现次数进行了从大到小的排序。
3. 倒着遍历桶，将每个桶里的元素取出来，并按照它的频次存入要返回的结果中。

附上有详细注释的Java代码（不保证简洁，毕竟是刷题的时候怎么想就怎么写的，等以后有机会二刷的时候再琢磨要怎么优化。

```java
class Solution {
    public String frequencySort(String s) {
        char[] chs = s.toCharArray();
        Map<Character, Integer> map = new HashMap<>();
        int maxTimes = -1;
        //统计每个字母的频次，并存入哈希表
        for(char c : chs){
            if(!map.containsKey(c)){
                map.put(c, 1);
            }else{
                map.put(c, map.get(c) + 1);
            }
            maxTimes = map.get(c) > maxTimes ? map.get(c) : maxTimes;
        }
        //新建一个桶，将字母存入索引为它的频次的桶里
        ArrayList<Character>[] buckets = new ArrayList[maxTimes + 1];
        for(char c : map.keySet()){
            int frequency = map.get(c);
            if(buckets[frequency] == null){
                buckets[frequency] = new ArrayList<>();
            }
            buckets[frequency].add(c);
        }
        //倒着遍历桶，将桶里的字母取出来，并按照它的频次插入字符数组中
        int p = 0;
        for(int i = maxTimes; i >= 0; i--){
            if(buckets[i] != null){
                for(char c : buckets[i]){
                    //buckets[i]这个桶里的字母的频次为i，因此要插入i个到结果集中
                    for(int j = 0; j < i; j++){
                        //复用chs作为结果集
                        chs[p++] = c;
                    }
                }
            }
        }
        return new String(chs);
    }
}
```