参照第767的贪心堆
```java
class Solution {
    public int[] rearrangeBarcodes(int[] barcodes) {
        if(barcodes == null || barcodes.length < 2) return barcodes;
        Map<Integer, Integer> map = new HashMap<>();
        for(int i : barcodes) {
            map.put(i, map.getOrDefault(i, 0) + 1);
        }
        //大顶堆
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> map.get(b) - map.get(a));
        for(int i : map.keySet()) {
            maxHeap.add(i);
        }
        int[] res = new int[barcodes.length];
        int idx = 0;
        while(maxHeap.size() > 1) {
            int a = maxHeap.poll();
            int b = maxHeap.poll();
            res[idx++] = a;
            res[idx++] = b;
            int freqA = map.get(a);
            int freqB = map.get(b);
            if(freqA > 1) {
                map.put(a, freqA - 1);
                maxHeap.add(a);
            } 
            if(freqB > 1) {
                map.put(b, freqB - 1);
                maxHeap.add(b); 
            }
        }
        //收尾
        if(maxHeap.size() > 0) res[idx] = maxHeap.poll();
        return res;
    }
}