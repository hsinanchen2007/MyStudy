### 解题思路
利用map缓存word统计计数
排序统计计数数组。取前K条数据。

### 代码

```java
class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        List<String> list=new ArrayList<>(k);
        Map<String,Integer> counts=new HashMap<>();
        for (String word:words){
            counts.put(word,counts.getOrDefault(word,0)+1);
        }
        List<Map.Entry<String,Integer>> sortList=new ArrayList<>(counts.entrySet());
        Collections.sort(sortList,(o1, o2) -> o2.getValue() == o1.getValue()?o1.getKey().compareTo(o2.getKey()):o2.getValue()-o1.getValue());
        for(int i=0;i<k;i++){
            list.add(sortList.get(i).getKey());
        }
        return list;
    }
}
```