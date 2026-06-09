### 解题思路
1.hashmap存储频率 
    i 2  love 2 leetcode 1  coding 1
2.建一个桶：
    1 leetcode coding   2  love i
3.对非空桶内数据进行排序
4.输出

### 代码

```java
import java.util.*;
class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String,Integer> map = new HashMap<>();
        for(String word:words){
            map.put(word,map.getOrDefault(word,0)+1);
        }

        List<String>[] buckets = new ArrayList[words.length+1];
        for(String key:map.keySet()){
            int fre = map.get(key);
            if(buckets[fre]==null){
                buckets[fre]=new ArrayList<>();
            }
            buckets[fre].add(key);
        }
      

        List<String> topk = new ArrayList<>();
        for(int i=buckets.length-1;i>=0&&topk.size()<k;i--){
            
            if(buckets[i]==null){
                continue;
            }
            Collections.sort(buckets[i]);
             if(buckets[i].size()<=(k-topk.size())){ 
                topk.addAll(buckets[i]);
            }else{ 
                topk.addAll(buckets[i].subList(0,k-topk.size()));
            }
        }
        
        return topk;
    }
}
```