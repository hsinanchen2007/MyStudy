### 解题思路
先统计次数，然后通过堆来求得topK

### 代码

```java
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        Map<Integer,Integer> counter = new HashMap<>( nums.length );
        for (int num : nums) {
            if(counter.containsKey( num )){
                Integer val = counter.get( num )+1;
                counter.put( num,val );
            }else{
                counter.put( num,1 );
            }
        }
        PriorityQueue<Map.Entry> topK = new PriorityQueue( ( o1, o2 ) -> {
            return (Integer)(( Map.Entry)o1).getValue() - (Integer)(( Map.Entry)o2).getValue();
        } );
        Iterator<Map.Entry<Integer, Integer>> iterator = counter.entrySet().iterator();
        while(iterator.hasNext()){
            topK.offer( iterator.next() );
            if(topK.size()>k){
                topK.poll();
            }
        }
         List<Integer> collect = new ArrayList<>( k );
        int index = 0;
        while(!topK.isEmpty()){
            collect.add( index,(Integer) topK.poll().getKey() );
            index++;
        }
        Collections.reverse( collect );
        return collect;
    }
}
```