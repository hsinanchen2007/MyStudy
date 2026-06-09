这个题和跳越游戏2那个题一模一样，只不过跳格子那个题是已经排序过的。
https://leetcode-cn.com/problems/jump-game-ii/

区间的左端点clips[i][0]，可以看成跳越游戏那个题的坐标。
区间的右端点clips[i][1]，可以看成跳越游戏那个题的跳越距离。
可恨腾讯竟然拿这个当笔试题。。。。。跳越游戏2可是hard题啊！！！


Java ac代码：
```
class Solution {
    public int videoStitching(int[][] clips, int T) {
        
        Arrays.sort(clips,new Comparator<int[]>() {
            @Override
            public int compare(int[] p1, int[] p2) {
                if(p1[0] != p2[0])return p1[0] - p2[0];
            return p2[1] - p1[1];
            }
        });
        
        int maxDis = 0;
        int last = 0;
        int ans = 0;
        for(int[]point : clips)
        {
            if(maxDis >= T)break;
            if(point[0] <= last)
                maxDis = Math.max(maxDis,point[1]);
            else
            {
                ans++;
                last = maxDis;
                if(point[0] > maxDis)break;
                maxDis = Math.max(maxDis,point[1]);
            }
        }
        if(last != maxDis)ans++;
        if(maxDis < T)return -1;
        return ans;
    }
}
```
