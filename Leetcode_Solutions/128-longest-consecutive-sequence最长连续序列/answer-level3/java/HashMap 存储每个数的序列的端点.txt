使用hashmap存储一个数的连续序列的端点位置
遍历过程中不断更新最长序列值
分三种情况
1. 该数的左右邻居都没出现过，则hm.put(n, n)  即存储它自己，
2. 只有左边或者右边出现过时，比如右边 n + 1 出现过，则把 n + 1 里边存储的值（右端点）存到n里边，同时，右端点存下n作为左端点，左边同理
3. 如果左右都出现过的话，先用n存下右端点，然后把n-1存储的左端点存下 n 存储的右端点，n 存储的右端点存下 n -1 存储的左端点。
说白了就是n作为中间值，把两边的序列连接起来，并且两头的数存下左右端点。

```
class Solution {
    public int longestConsecutive(int[] nums) {
        HashMap<Integer, Integer> hm = new HashMap<>();
        if(nums.length == 0) return 0;
        int max = 1;
        for(int n: nums){
            if(!hm.containsKey(n)){
                if(hm.containsKey(n+1)){
                    hm.put(n, hm.get(n + 1));
                    hm.put(hm.get(n + 1), n);
                    max = Math.max(max, (hm.get(n) - n) + 1);
                    if(hm.containsKey(n-1)){
                        hm.put(hm.get(n), hm.get(n - 1));
                        int left_index = hm.get(n - 1);
                        hm.put(hm.get(n - 1), hm.get(n));
                        max = Math.max(max, (hm.get(left_index) - hm.get(hm.get(n))) + 1);  
                    }
                }else if(hm.containsKey(n-1)){
                    hm.put(n, hm.get(n - 1));
                    hm.put(hm.get(n - 1), n);
                    max = Math.max(max, (n - hm.get(n)) + 1);
                }else{
                    hm.put(n, n);
                }
            }
        }
        return max;
    }
}
```
