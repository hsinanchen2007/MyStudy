优化为right, left 双数组记录左右边界
/*执行结果：
通过
显示详情
执行用时 :
5 ms
, 在所有 Java 提交中击败了
95.20%
的用户
内存消耗 :
42.5 MB
, 在所有 Java 提交中击败了
44.98%
的用户*/
```
class Solution {
    public int largestRectangleArea(int[] heights) {
        int len = heights.length;
        if(len==0)return 0;
        int max=0;
        int[] ll = new int[len];
        ll[0]=0;
        for(int i=1; i<len; i++){
            if(heights[i]>heights[i-1]){
                ll[i]=i;
            }else if(heights[i]==heights[i-1]){
                ll[i]=ll[i-1];
            }else{
                ll[i]=0;
                for(int j=ll[i-1]-1;j>=0;j--){
                    if(heights[i]>heights[j]){
                        ll[i]=j+1;
                        break;
                    }
                }
            }
        }
        int[] rr = new int[len];
        rr[len-1]=len-1;
        
        for(int i=len-2;i>=0;i--){
            if(heights[i]>heights[i+1]){
                rr[i]=i;
            }else if(heights[i]==heights[i+1]){
                rr[i]=rr[i+1];
            }else{
                rr[i]=len-1;
                for(int j=rr[i+1]+1;j<len;j++){
                    if(heights[i]>heights[j]){
                        rr[i]=j-1;
                        break;
                    }
                }
            }
            
        }
        
        for(int i=0; i<len; i++){
            if(heights[i]*(rr[i]-ll[i]+1)>max)max=heights[i]*(rr[i]-ll[i]+1);
        }
        return max;
    }
}
```

暴力迭代，每个点面积=高度*（右边界-左边界）
执行结果：
通过
显示详情
执行用时 :
629 ms
, 在所有 Java 提交中击败了
20.92%
的用户
内存消耗 :
43.2 MB
, 在所有 Java 提交中击败了
32.82%
的用户
```
class Solution {
    int max=0;
    public int largestRectangleArea(int[] heights) {
        int len = heights.length;
        if(len==0)return 0;
        for(int i=0; i<len; i++){
            int l=0;
            for(int j=i-1;j>=0;j--){
                if(heights[j]<heights[i]){
                    l=j+1;
                    break;
                }
            }
            int r=len-1;
            for(int j=i+1;j<len;j++){
                if(heights[j]<heights[i]){
                    r=j-1;
                    break;
                }
            }
            int res = heights[i]*(r-l+1);
            if(res>max)max=res;
        }
        return max;
    }
}
```
