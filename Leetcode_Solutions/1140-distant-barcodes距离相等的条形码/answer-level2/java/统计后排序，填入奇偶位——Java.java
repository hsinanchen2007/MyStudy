 思路：参考评论中[@strengthen](https://leetcode-cn.com/u/strengthen) 这位大佬的思路，Java实现，借助HashMap，将TreeMap按值排序后，按奇偶位填入即可。做了个简单的翻译。。。虽然没能看懂Swift代码，但是好像理解到了思路，AC了。效率不高，毕竟只学到了皮毛。。。
<br/><br/>
代码：
```processing
class Solution {
    public int[] rearrangeBarcodes(int[] barcodes) {
        HashMap<Integer,Integer> map = new HashMap<>();
        ValueComparator vc =  new ValueComparator(map);// 自定义排序方式，将TreeMap按值排序
        
        for (int k : barcodes) {
            if (map.containsKey(k)) {
                map.put(k,map.get(k) + 1);
            } else {
                map.put(k,1);
            }
        }
        
        TreeMap<Integer,Integer> treeMap = new TreeMap<>(vc);
        treeMap.putAll(map);
        
        int ans[] = new int[barcodes.length];
        int i = 0;
        
        for (int key : treeMap.keySet()) {
            for (int j = 0;j < map.get(key);j++) {
                ans[i] = key;
                i += 2;
                if (i >= ans.length) {
                    i = 1;
                }
            }
        }
        
        return ans;
    }
    
    static class ValueComparator implements Comparator<Integer> { 
        Map<Integer, Integer> base;
        
        public ValueComparator(Map<Integer, Integer> base) { 
            this.base = base; 
        }
        
        public int compare(Integer a, Integer b) {
            if (base.get(a) >= base.get(b)) {
                return -1;
            } else {
                return 1;
            }
        }
    }
}
```

