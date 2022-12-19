##### 个人第一次写题解
个人解法思路，欢迎大佬指正。 此题看起来简单，关键是要找到A字符串叠加终止的长度，即 2*A+B，然后利用String.indexOf() 判断 A 是否包含 B，如果不包含且A的长度小于终止长度，则叠加A一次，计数器加1，当找到A包含B时，返回计数值，如果A的长达大于终止长度，都没有满足A包含B的话，直接返回-1。
```
class Solution {
    public int repeatedStringMatch(String A, String B) {
        int count=1;
        StringBuilder sb=new StringBuilder();
        sb.append(A);
        while(sb.length()<2*A.length()+B.length())
        {
            if(sb.indexOf(B)==-1)
            {
                 sb.append(A);
                 count++;   
            }
            else return count; 
        }
      return -1;
    }
}
```