### 解题思路
* 词频记录一般会想到采用Map
* 如果对map排序可能会有点难度，优先队列针对map的Entry对象排序一般很难想到
* 根据词频还原原单词也是一个技术活

### 代码

```java
class Solution {
    public String frequencySort(String s) {
        Map<Character,Integer> map = new HashMap<>();
        for (char ch:s.toCharArray()) {
            map.put(ch,map.getOrDefault(ch,0)+1);
        }
        Queue<Map.Entry<Character,Integer>> queue = new PriorityQueue<>(
        (a,b) -> b.getValue() - a.getValue());
        Iterator<Map.Entry<Character,Integer>> it = map.entrySet().iterator();
        while (it.hasNext()) {
            queue.add(it.next());
        }
        Map.Entry<Character,Integer> entry = null;
        StringBuilder sb = new StringBuilder();
        while(!queue.isEmpty()) {
           entry =  queue.poll();
           int frequency = entry.getValue();
           for(int i = 0; i < frequency; i++) {
               sb.append(entry.getKey());
           }
        }
        return sb.toString();
    }
}
```