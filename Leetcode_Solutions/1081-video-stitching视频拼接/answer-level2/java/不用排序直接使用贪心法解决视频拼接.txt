### 解题思路
![微信图片_20200130171639.png](https://pic.leetcode-cn.com/047fd870d61ae9d205b39b9fac3802ea4b057922be9d81e323f795ce8a2d3fb0-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200130171639.png)

### 代码

```java
class Solution {
   //此方法通过上一个区间的末端值e,去搜索包含末端值的最长区间
   public int getNextLongest(int e,int[][]clips){
        
        int max=0;
        for(int i=0;i<clips.length;i++){
          if(clips[i][0]<=e&&e<=clips[i][1]) max=Math.max(max,clips[i][1]);
        }
        return max;
        
    }
    
    public int videoStitching(int[][] clips, int T) {
        
        int res=0;//记录片段结果
        int e=0;//每个片段的末端值
        int tmp=0;//辅助变量
        while (e<T){
            tmp=e;//暂时保存e的值
            e=getNextLongest(e,clips);
            if(e==tmp) return -1;//如果寻找的下一个区间的最大值,和之前不变说明无法完成任务,片段缺失
            res++;
        }
        return res;
    }
}
```