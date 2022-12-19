### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> times = new HashMap<Integer, Integer>();//计数
        for (int i = 0; i < nums.length; i++) {
            times.put(nums[i], times.getOrDefault(nums[i], 0) + 1);
        }
        int[] heap = new int[times.size()]; //最大堆
        int tail = 0;
        Iterator<Integer> keys = times.keySet().iterator();
        //建堆
        if (keys.hasNext()) {
            Integer key = keys.next();
            heap[tail++] = key;
        }
        while (keys.hasNext()) {
            Integer key = keys.next();
            heap[tail++] = key;
            int p = tail - 1;
            while (p > 0 && times.get(heap[p]) > times.get(heap[(p-1)/2])) {
                int t = heap[p];
                heap[p] = heap[(p-1)/2];
                heap[(p-1)/2] = t;
                p = (p-1)/2;
            }
        }
        tail--;
        
        List<Integer> res = new ArrayList<Integer>();
        //前k大，
        for (int i = 0; i < k; i++) {
            res.add(heap[0]);
            heap[0] = heap[tail--];
            //heap[tail+1] = res.get(i);
            int p = 0;
            while (true) {
                int l = p*2 + 1;
                int r = l + 1;
                if (l > tail) { //无子
                    break;
                }
                else {
                    if (r > tail) { //只有左
                        if (times.get(heap[p]) < times.get(heap[l])) {
                            int t = heap[p];
                            heap[p] = heap[l];
                            heap[l] = t;
                            p = l;
                        } 
                        else {
                            break;
                        }
                    }
                    else {  //有左有右
                        int next;   //最大子
                        if (times.get(heap[l]) > times.get(heap[r])) {
                            next = l;
                        }
                        else {
                            next = r;
                        }
                        if (times.get(heap[p]) < times.get(heap[next])) {
                            int t = heap[p];
                            heap[p] = heap[next];
                            heap[next] = t;
                            p = next;
                        }
                        else {
                            break;
                        }
                    }
                }
            }
        }
        return res;
    }
}
```