### 解题思路
 1、构造一个hashMap wordCountMap
     key为words的元素值,value为num出现的次数
2、构造一个优先级队列priorityQueue,队列里面保存的是words数组的元素值,队列的排序法则按照
     (s1,s2)->{
            int compareCount = wordCountMap.get(s1).compareTo(wordCountMap.get(s2);
            if(compareCount!=0){
                return compareCount;
            }else{
                //这里为什么要将s2放在前面呢
                //因为优先级队列出现次数小的放在前面，但是输出的时候出现次数小的在后面
                //题意要求按照字典顺序排序,那么就应该把字典顺序较小的字符串放后面,所以就出现了反向比较
                return s2.compareTo(s1);
            }
        })
3、循环wordCountMap的keySet,将key向priorityQueue里面添加,如果队列的大小>k
      则将第一个元素弹出
4、将priorityQueue导出为list,注意priorityQueue是从小到大排序,所以在最终结果输出的时候需要反

### 代码

```java
class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String,Integer> wordCountMap = new HashMap<>();
        for(String word:words){
            wordCountMap.put(word,wordCountMap.getOrDefault(word,0)+1);
        }
        PriorityQueue<String> priorityQueue = new PriorityQueue<>((s1,s2)->{
            Integer s1Count = wordCountMap.get(s1);
            Integer s2Count = wordCountMap.get(s2);
            if(s1Count!=s2Count){
                return s1Count.compareTo(s2Count);
            }else{
                return s2.compareTo(s1);
            }
        });
        for(String word:wordCountMap.keySet()){
            priorityQueue.add(word);
            if(priorityQueue.size()>k){
                priorityQueue.poll();
            }
        }
        List<String> resultList = new ArrayList<>();
        while(!priorityQueue.isEmpty()){
            resultList.add(priorityQueue.poll());
        }
        Collections.reverse(resultList);
        return resultList;
    }
}
```