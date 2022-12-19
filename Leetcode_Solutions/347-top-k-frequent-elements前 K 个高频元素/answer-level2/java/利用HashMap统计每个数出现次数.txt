统计每个数出现的次数，根据出现的次数再得到数，即为最终结果。
```java
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        List<Integer> res = new ArrayList();
        // key为值 value为出现次数
        HashMap<Integer,Integer> map = new HashMap();
        // 统计每个数出现的次数
        for(int i : nums){
            map.put(i,map.getOrDefault(i,0)+1);
        }
        // list数组中每一个位置为这个数出现的次数 值为出现次数这么多的数
        List<Integer>[] list = new List[nums.length+1];
        for(int key : map.keySet()){
            // 出现的次数
            int i = map.get(key);
            if(list[i]==null) list[i] = new ArrayList();
            // 当前次数中 包含那些数
            list[i].add(key);
        }
        for(int i=list.length-1;i>=0 && res.size()<k;i--){
            if(list[i]==null) continue;
            // 该题没有出现频率相同的数字 不需要考虑其他情况
            res.addAll(list[i]);
        }
        return res;
    }
}
```