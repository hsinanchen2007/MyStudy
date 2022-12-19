### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        PriorityQueue<Integer> heap = new PriorityQueue<>(new Comparator<Integer>(){
            @Override
            public int compare(Integer a, Integer b){
                return b - a;
            } 
        });
        int res[] = new int[k];
        for(int val: arr){
            if(heap.size() >= k){
                if(!heap.isEmpty() && heap.peek() > val){
                    heap.poll();
                    heap.add(val);
                }else{
                    continue;
                }
            }else{
                heap.add(val);
            }        
        }
        int index = 0;
        for(Integer v: heap){
            res[index++] = v;
        }
        return res;
    }
}
```