### 解题思路
1. hashset
2. 优先队列，override比较方法（大顶堆or小顶堆）
3. 输出

方法：
1. for(char ch: chs)
2.  PriorityQueue<Map.Entry<Character, Integer>> q = new PriorityQueue<>((o1, o2) ->{
        if(o1.getValue()==o2.getValue())
        {
            return o1.getKey().compareTo(o2.getKey());
        }
        return o2.getValue() - o1.getValue();});

        for(Map.Entry<Character, Integer> entry: count.entrySet()){
            q.offer(entry);
        }
    q.poll();

### 代码

```java
class Solution {
    public String frequencySort(String s) {
        Map<Character, Integer> count = new HashMap<Character, Integer>();
        char [] chs = s.toCharArray();
        for(char ch: chs)
        {
            if(count.containsKey(ch))
            {
                count.put(ch, count.get(ch)+1);
            }
            else count.put(ch, 1);
        }
        PriorityQueue<Map.Entry<Character, Integer>> q = new PriorityQueue<>((o1, o2) ->{
        if(o1.getValue()==o2.getValue())
        {
            return o1.getKey().compareTo(o2.getKey());
        }
        return o2.getValue() - o1.getValue();});

        for(Map.Entry<Character, Integer> entry: count.entrySet()){
            q.offer(entry);
        }
        StringBuilder stringBuilder = new StringBuilder();
        while(!q.isEmpty())
        {
            Map.Entry<Character, Integer> temp = q.poll();
            for(int i =0; i < temp.getValue();i++)
            {
                stringBuilder.append(temp.getKey());
            }
        }
        return stringBuilder.toString();
        
    }
}
```