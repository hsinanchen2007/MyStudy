### 解题思路
    本题的思路比较简单，遍历字符串中的每个字符，统计相应字符出现的频率，其中balloon需要两个l,两个o，因此如何确定最大的“balloon"数量：
将l和o的个数各除以2（向下取整）。比较搜索得到的a,b,l,o,n中最小的频率就是balloon的最大数量

### 代码

```java
class Solution {
    public int maxNumberOfBalloons(String text) {
        int[] counter=new int[26];
        for(int i=0;i<text.length();i++)
            counter[text.charAt(i)-'a']++;
        //ballon中字符l和o要使用两次
        counter[11]/=2;
        counter[14]/=2;
        int[] idx=new int[]{0,1,11,13,14};
        int res=Integer.MAX_VALUE;
        for(int i:idx)
            res=Math.min(res,counter[i]);
        return res;
    }
}
```