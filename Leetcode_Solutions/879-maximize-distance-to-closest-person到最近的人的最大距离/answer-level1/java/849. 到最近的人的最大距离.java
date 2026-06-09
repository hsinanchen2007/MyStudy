Java代码：
```java
class Solution {
    public int maxDistToClosest(int[] seats) {
        int max = 0;
        int cur = 0;
        int i = 0;
        int fir = 0;
        for(i = 0;i < seats.length ;i++)
            if(seats[i] == 1)
            {
                fir = i;
                break;
            }
        for( ; i < seats.length - 1 ; i++)
        {
            if(seats[i] == 0)
                if(seats[i+1] == seats[i])
                    cur ++;
            else 
            {
                max = Math.max(max,cur);
                cur = 0;
            }
        }
        if(i == seats.length - 1 && cur  > (max / 2) )
                 return Math.max(cur + 1,fir);        
        return Math.max((max + 2) / 2,fir);
    }
}
```
分为三种情况
1 开头从 `0` 到 `1` 记录第一个`1`的坐标作为第一段距离
2 记录最长的 `1`到 `1` 之间的距离 `+ 2`除以`2`
3 结尾从`1`到`0` 记录最后这段距离
三者比较取最长