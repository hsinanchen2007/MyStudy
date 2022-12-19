### 解题思路
将数组元素放入优先队列中，每一次比较优先队列中的最小值
将最小值替换
后输出最终的答案
### 代码

```java
class Solution {

    private class Freq implements Comparable<Freq>{
        public  int e, freq;
        public Freq(int e,int freq){
          this.e=e;
          this.freq=freq;
          }

        @Override
        public int compareTo(Freq another) {
            if (this.freq>another.freq)
                return 1;
            else if (this.freq<another.freq)
                return -1;
            else
                return 0;
        }
    }

    public List<Integer> topKFrequent(int[] nums, int k) {
        TreeMap<Integer,Integer> map=new TreeMap<>();
         for (int i:nums){
             if (map.containsKey(i)){
                 map.put(i,map.get(i)+1);
             }else
                 map.put(i,1);
         }

         //优先队列
        PriorityQueue<Freq> pq=new PriorityQueue<>();
         for (int key:map.keySet()){
             if (pq.size()<k){
                 pq.add(new Freq(key,map.get(key)));
             }else if (map.get(key)>pq.element().freq){
              pq.remove();
              pq.add(new Freq(key,map.get(key)));
             }
         }
        LinkedList<Integer>res=new LinkedList<>();
         while(!pq.isEmpty()){
             res.add(pq.remove().e);
         }
         return res;
    }
}
```