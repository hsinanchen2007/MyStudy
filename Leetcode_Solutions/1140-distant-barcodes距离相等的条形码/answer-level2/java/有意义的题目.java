### 解题思路
用map统计词频
接着用大顶堆根据频数排序
每次从大顶堆中选择两个元素，摆放在新数组中，接着把这两个元素的频次减一，重新扔回大顶堆，一直重复这个步骤，直到大顶堆为空即可。
有点像哈夫曼编码的感觉。

### 代码

```java
class Solution {
    public int[] rearrangeBarcodes(int[] barcodes) {
        Map<Integer,Integer> map = new HashMap<>();
        PriorityQueue<Integer> max = new PriorityQueue<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return map.get(o2) - map.get(o1);
            }
        });
        for (int barcode : barcodes) {
            if (map.containsKey(barcode))
                map.put(barcode,map.get(barcode) + 1);
            else
                map.put(barcode,1);
        }
        max.addAll(map.keySet());
        int[] res = new int[barcodes.length];
        int index = 0;
        while (max.size() >= 2){
            Integer a = max.remove();
            int a_cnt = map.get(a);
            Integer b = max.remove();
            int b_cnt = map.get(b);
            res[index++] = a;
            res[index++] = b;
            if (a_cnt > 1){
                map.put(a,a_cnt-1);
                max.add(a);
            }
            if (b_cnt > 1){
                map.put(b,b_cnt-1);
                max.add(b);
            }
        }
        if (max.isEmpty())
            return res;
        else
            res[index++] = max.remove();
        return res;
    }
}
```