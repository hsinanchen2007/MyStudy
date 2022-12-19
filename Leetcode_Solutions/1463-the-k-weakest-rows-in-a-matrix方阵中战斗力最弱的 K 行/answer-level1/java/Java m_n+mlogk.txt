既然先给了k一定注意m和n的关系。不是方阵的话，行可能很大列很少，此时直接sort的复杂度是m*n+mlogm。
是方阵的话不用说怎么样都是O(n^2)。
用最大堆保证堆里只有k个元素，超过k时把最大的元素剔除，使得时间复杂度变为m*n+mlogk。
这对k小，n小，m大的情况非常有帮助。
```
class Solution {
    private Map<Integer,Integer> map = new HashMap();
    public int[] kWeakestRows(int[][] mat, int k) {
        for(int i=0;i<mat.length;i++){
            int count=0;
            for(int j=0;j<mat[0].length;j++){
                if(mat[i][j]==0) break;
                count++;
            }
            map.put(i,count);
        }
        PriorityQueue<Integer> maxHeap = new PriorityQueue(Collections.reverseOrder(new Comparator<Integer>(){
            public int compare(Integer a,Integer b){
                return map.get(a)==map.get(b)?a-b:map.get(a)-map.get(b);
            }
        }));
        for(int i=0;i<mat.length;i++){
            maxHeap.offer(i);
            if(maxHeap.size()>k) maxHeap.poll();
        }
        int[] res = new int[k];
        int index = k-1;
        while(maxHeap.size()>0) res[index--]=maxHeap.poll();
        return res;
    }
}
```
