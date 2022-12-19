### 解题思路
1、构造一个hashMap numCountMap
    key为nums的元素值,value为num出现的次数
2、构造一个优先级队列priorityQueue,队列里面保存的是nums数组的元素值,队列的排序法则按照
     (num1,num2)->numCountMap.get(num1).compareTo(numCountMap.get(num2))
3、循环numCountMap的keySet,将key向priorityQueue里面添加,如果队列的大小>k
      则将第一个元素弹出
4、将priorityQueue导出为list,注意priorityQueue是从小到大排序,所以在最终结果输出的时候需要反转。

### 代码

```java
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        Map<Integer,Integer> numCountMap = new HashMap<>();
        for(int num:nums){
            numCountMap.put(num,numCountMap.getOrDefault(num,0)+1);
        }
        //由小到大排序的优先级队列
        PriorityQueue<Integer> priorityQueue = new PriorityQueue<>((num1,num2)->numCountMap.get(num1).compareTo(numCountMap.get(num2)));
        for(Integer num : numCountMap.keySet()){
            priorityQueue.add(num);
            if(priorityQueue.size()>k){
                priorityQueue.poll();
            }
        }
        List<Integer> resultList = new ArrayList<>();
        while(!priorityQueue.isEmpty()){
            resultList.add(priorityQueue.poll());
        }
        Collections.reverse(resultList);
        return resultList;
    }

   
}
```