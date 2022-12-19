如果数组为空：
则直接返回0；
否则 答案ans至少为1。

对数组进行遍历：
如果map中不包含当前数值x-公差dif的key，即当前数值对应数列的上一项：
就将x和默认最小的序列长度1存入map中；
否则 取得此前保存的最大长度+1为len，
与ans进行比较，取较大值，
将x和len保存到map当中。

```
class Solution {
    public int longestSubsequence(int[] a, int dif) {
        if(a.length==0)
            return 0;
        Map <Integer, Integer> map = new HashMap<>();
        int ans=1;
        for(int x:a){
            if(!map.containsKey(x-dif)) {
                map.put(x,1);
            } else {
                int len = map.get(x-dif)+1;
                ans = Math.max(ans,len);
                map.put(x,len);
            }
        }
        return ans;
    }
}
```
