
 算法思想:
   
    1: 整个数组中,劳累天数永远大于不劳累的天数,那么最长的表现良好时间段就是整个数组
    2: 在选中的最长表现良好时间段中,劳累时间永远比不劳累多一天
    使用1标识劳累时间天数，使用-1标识不劳累天数
    将数组的进行累加和,符合上述两种情况
### 代码

```java
class Solution {
    public int longestWPI(int[] hours) {
        Map<Integer, Integer> map = new HashMap<>();
        int sum=0,longest=0;
        for(int i=0;i<hours.length;i++){
            sum+=(hours[i]>8)?1:-1;
            if(sum>0) longest=i+1;
            else{
                //如果不存在设置,存在就不设置了
                map.putIfAbsent(sum, i);
                //劳累时间永远比不劳累多一天
                if(map.containsKey(sum-1)) longest = Math.max(longest, i - map.get(sum - 1));
            }
        }
        return longest;
    }
}
```