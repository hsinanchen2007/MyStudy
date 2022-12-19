
### 代码

```java
class Solution {
    public int[][] merge(int[][] intervals) {
        if(intervals.length==0){
            return intervals;
        }
        Arrays.sort(intervals,(i, j) -> Integer.compare(i[0],j[0]));
        List<int[]> inQueue = new LinkedList<>();
        Collections.addAll(inQueue,intervals);
        List<int[]> outQueue = new LinkedList<>();
        while (inQueue.size()>1){
            int[] i = inQueue.remove(0);
            int[] j = inQueue.remove(0);
            if(i[0]==j[0]){
                if(i[1]>=j[1]){
                    inQueue.add(0,i);
                }else{
                    inQueue.add(0,j);
                }
            }else{
                if(i[1]<j[0]){
                    outQueue.add(i);
                    inQueue.add(0,j);
                }else{
                    if(i[1]>=j[1]){
                        inQueue.add(0,i);
                    }else{
                        inQueue.add(0,new int[]{i[0],j[1]});
                    }
                }
            }
        }
        outQueue.add(inQueue.get(0));
        return outQueue.toArray(new int[][]{});
    }
}
```