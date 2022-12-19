一开始没理解题目
- "krrgw" , "zjxss" , 19
怎么看都是3 结果悲剧了 !

就是一道简单滑动窗口
```
class Solution {
    public int equalSubstring(String s, String t, int maxCost) {
        int length = s.length();
        int cost = 0;
        int l = -Integer.MAX_VALUE;
        int start = 0; //窗口左界限
        /*
        遍历窗口右界限i
            */
        for (int i = 0;i<length;i++){
            int dif = Math.abs(s.charAt(i) - t.charAt(i));

            if (dif + cost <=maxCost){
                /*
                总消费小于maxCost
                */
                cost +=dif;
                l = Integer.max(l,i - start);
            }else if (dif>maxCost){
                /*
                相差大于maxCost,重置start和cost
                    */
                if (start == length - 1){
                    return l == -Integer.MAX_VALUE ? 0 : l + 1;
                }else {
                    start = i+1;
                    cost = 0;
                }
            }else {
                /*
                窗口左界限向右缩小,直到cost小于maxCost
                    */
                cost = cost + dif;
                while (cost>maxCost){
                    cost -= Math.abs(s.charAt(start) - t.charAt(start));
                    start++;
                }
            }
        }
        return l == -Integer.MAX_VALUE ? 0 : l + 1;
    }
}
```

