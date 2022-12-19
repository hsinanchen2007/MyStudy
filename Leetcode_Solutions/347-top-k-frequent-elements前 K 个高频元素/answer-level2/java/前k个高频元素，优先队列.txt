优先级队列与哈希表
```java []
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        HashMap<Integer,Integer> map=new HashMap();
        PriorityQueue<Integer> Q=new PriorityQueue((n1,n2) -> map.get(n1)-map.get(n2));
        int count;
        for(int num:nums){
            count=map.getOrDefault(num,0)+1;
            map.put(num,count);
        }
        for(Integer key:map.keySet()){
            Q.offer(key);
            if(Q.size()>k) Q.poll();
        }
        List<Integer> res=new LinkedList();
        while(Q.isEmpty()==false) res.add(Q.poll());
        Collections.reverse(res);
        return res;
    }
}
```

