假设在i时刻，刚好左侧灯全亮，那么打开的灯的计数值为cur=1+2+...+i；
而实际i时刻开的灯的值tmp=light[0]+...+light[i-1];
所以遍历数组，当有一个时刻tmp==cur，就是打开的灯都是蓝色。

代码：
```
class Solution {
    public int numTimesAllBlue(int[] light) {
        int res=0;
        int n=light.length;
        int cur=0;
        int tmp=0;
        for(int i=0;i<n;i++){
            tmp+=light[i];
            cur+=i+1;
            if(cur==tmp){
                res++;
            }
        }
        return res;
    }
}
```
