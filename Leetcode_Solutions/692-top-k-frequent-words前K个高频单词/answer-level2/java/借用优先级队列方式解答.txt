### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String,Integer> mapSave = new HashMap<>();
        List<String> res = new ArrayList<>();
        buildmap(words,mapSave);
        PriorityQueue<Item> queue = new PriorityQueue<>(1,(o1, o2) -> o1.count == o2.count ? o1.str.compareTo(o2.str): o2.count - o1.count);
        convertToqueue(queue,mapSave);
        for (int i = 0 ; i < k; i++){
            res.add(queue.poll().str);
        }
        return res;
    }
    private static void convertToqueue(PriorityQueue<Item> queue, Map<String,Integer> mapSave){
        for (Map.Entry<String,Integer> map: mapSave.entrySet()){
            Item tmp = new Item(map.getKey(),map.getValue());
            queue.offer(tmp);
        }
    }
    private static void buildmap(String[] words, Map<String,Integer> mapSave){
        for (int i = 0; i < words.length; i++){
            if (mapSave.containsKey(words[i])){
                mapSave.put(words[i],mapSave.get(words[i]) + 1);
            }else mapSave.put(words[i],1);
        }
    }
    static class Item{
        String str;
        Integer count;
        public Item(String str, Integer count) {
            this.str = str;
            this.count = count;
        }
    }
}
```