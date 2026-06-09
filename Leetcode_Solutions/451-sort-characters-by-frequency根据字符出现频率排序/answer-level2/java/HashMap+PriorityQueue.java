### 解题思路
1. 首先统计每个字母的出现的次数，用hashmap来实现（固定套路）
2. 然后对这些次数进行排序，用优先队列PriorityQueue进行实现（可以自定义比较器）
3. 按照频率大小进行字母输出（由可以动态更新的StringBuilder进行实现）

- 时间复杂度为On（虽然出现嵌套for循环，但是累加起来为单词的长度）
- 空间复杂度为On (构造Hashmap PriorityQueue StringBuilder)

### 代码

```java
class Solution {
    public String frequencySort(String s) {
        HashMap<Character,Integer> map = new HashMap<>();
        for(int i = 0;i<s.length();i++){
            map.put(s.charAt(i),map.getOrDefault(s.charAt(i),0)+1);
        }
        System.out.println(map.keySet());
        PriorityQueue<Character> heap = new PriorityQueue<>((Character e1,Character e2)->map.get(e2)-map.get(e1)); //大顶堆
        for(Character key : map.keySet()){
            heap.add(key);
        }
        StringBuilder ans = new StringBuilder();
        while(!heap.isEmpty()){
            char ss = heap.poll();
            int times = map.get(ss);
            for (int i=0;i<times;i++){
                ans.append(ss);
            }

        }
        return ans.toString();


    }
}
```