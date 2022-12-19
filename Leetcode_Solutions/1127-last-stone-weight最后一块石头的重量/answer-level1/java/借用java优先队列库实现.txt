### 解题思路
重写优先队列的比较器，将最小堆变成最大堆，然后按照题意即可实现

### 代码

```java
class Solution {
    public int lastStoneWeight(int[] stones) {
        
        PriorityQueue<Integer> p=new PriorityQueue<>(new Comparator<Integer>(){
            @Override
            public int compare(Integer i1,Integer i2){
                return i2-i1;
            }
        });
        for(int stone:stones){
            p.offer(stone);
        }
        while(!p.isEmpty()&&p.size()!=1){
            int y=p.poll();
            int x=p.poll();
            if(y!=x){
                p.offer(y-x);
            }
        }
        if(p.isEmpty()){
            return 0;
        }
        return p.poll();
    }
}
```