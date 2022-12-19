### 解题思路

1、构造一个hashMap numCountMap
       key为nums的元素值,value为num出现的次数
2、构造一个单向递增链表LinkedList<Integer> topKList,里面所有的元素按照numCount排序
3、循环numCountMap的keySet,将key向topKList里面添加,如果链表的大小>k
           则将第一个元素弹出
        注意在插入的过程中要保持链表的单调递增性
4、将topKList返回,注意topKList是从小到大排序,所以在最终结果输出的时候需要反转。

### 代码

```java
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
            Map<Integer,Integer> numCountMap = new HashMap<>();
        for(int num:nums){
            numCountMap.put(num,numCountMap.getOrDefault(num,0)+1);
        }
        //由小到大排序的优先级队列--使用链表结构
        LinkedList<Integer> topKList = new LinkedList<>();
        for(Integer num :numCountMap.keySet()){
            pushNumIntoTopKList(num,topKList,numCountMap);
            if(topKList.size()>k){
                topKList.pollFirst();
            }
        }
        Collections.reverse(topKList);
        return topKList;
    }

     /**
     * 将num推入到topKList，并保持从小到大的顺序
     *
     * @param num
     * @param topKList
     * @param numCountMap
     */
    private void pushNumIntoTopKList(int num,LinkedList<Integer> topKList,Map<Integer,Integer> numCountMap){
        if(topKList.isEmpty()){
            topKList.add(num);
            return;
        }
        int length = topKList.size();
        boolean insertFlag = false;
        int i = 0;
        for(;i<length;i++){
            if(numCountMap.get(num)>numCountMap.get(topKList.get(i))){
                continue;
            }
            //说明topKList[i-1]<num<topKList[i]
            if(i==0){
                topKList.addFirst(num);
            }else{
                topKList.add(i,num);
            }
            insertFlag = true;
            break;
        }
        if(i==length && !insertFlag){
            //说明达到了链表末尾，num比链表里面所有元素都大
            topKList.addLast(num);
        }
    }
}
```