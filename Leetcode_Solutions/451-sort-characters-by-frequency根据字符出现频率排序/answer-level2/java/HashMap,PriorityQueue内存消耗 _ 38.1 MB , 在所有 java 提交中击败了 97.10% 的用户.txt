### 解题思路
    /**
     * 根据字符出现频率排序
     * @param "tree"
     * @return eetr or eert
     * 1. 使用HashMap存储每个元素的出现次数
     * 2. 使用PriorityQueue队列自定义排序规则,对HashMap中的每个Entry入队列
     * 3. 使用StringBuilder完成字符拼接
     */

### 代码

```java
class Solution {
    public String frequencySort(String s) {
        Map<Character,Integer> map = new HashMap<>(16);
        char[] chs = s.toCharArray();
        for(char ch : chs){
            map.put(ch,map.getOrDefault(ch,0) + 1);
        }

        PriorityQueue<Map.Entry<Character, Integer>> q = new PriorityQueue<>((o1, o2) -> {
            //按照出现次数高到低，出现次数相同相等按字符
            if(o1.getValue().equals(o2.getValue())){
                return o1.getKey().compareTo(o2.getKey());
            }
            return o2.getValue() - o1.getValue();
        });

        for(Map.Entry<Character, Integer> entry : map.entrySet()){
            q.offer(entry);
        }


        StringBuilder stringBuilder = new StringBuilder();
        while(!q.isEmpty()){
            final Map.Entry<Character, Integer> item = q.poll();
            for (int i = 0; i < item.getValue(); i++) {
                stringBuilder.append(item.getKey());
            }
        }
        return stringBuilder.toString();

    }
}
```