### 方法一:
先找到峰頂，再向左右查找，其優點為思路簡單，撰寫容易。

### 代码

```java
class Solution {
    public int longestMountain(int[] A) {
        if(A==null||A.length<3) return 0;
        int max=0;
        for(int ix=1;ix<A.length-1;ix++){
            if(A[ix-1]<A[ix]&&A[ix]>A[ix+1]){//找到峰頂
                int lft=ix-1,rgh=ix+1;
                while(lft>0 && A[lft-1]<A[lft]) lft--;//向左查找
                while(rgh<A.length-1 && A[rgh]>A[rgh+1]) rgh++;//向右查找
                int len=rgh-lft+1;//計算山脈長度
                max=Math.max(max,len>=3?len:0);
            }
        }
        return max;
    }
}
```

### 方法二:
以 while 迴圈 由左向右持續檢視陣列中的點，在每次迴圈操作中，以完成辨識一座山(一個主題)為目標。
若成功辨識一座山，則計算山長，保留山長最大值。

```java
class Solution {
    public int longestMountain(int[] A) {
        if(A==null||A.length<3) return 0;
        int cur=0,max=0;
        while(cur<A.length){
            int strt=-1;
            // 持續向右搜尋斜率向上的線段,遇到第一個符合後停止
            while(cur<A.length-1 && A[cur]>=A[cur+1]) cur++; 
            if(cur<A.length-1 && A[cur]<A[cur+1]) strt=cur; // 確認向上斜率線段存在
            else break;//若找不到, 則不存在 山型線段
            // 持續向右滑動，直到站在山峰
            while(cur<A.length-1 && A[cur]<A[cur+1]) cur++;
            // 若當前為斜率向下的線段, 則持續向右滑動
            while(cur<A.length-1 && A[cur]>A[cur+1]) cur++;
            int end=-1;
            if(cur<A.length && A[cur-1]>A[cur]) end=cur; // 確認當前斜率向下線段存在
            else continue;//若找不到, 表此次山型無法結束, 找下一個
            int len=end-strt+1;// 計算山長度
            max=Math.max(max,len>=3?len:0);// 保留山長最大值
        }
        return max;
    }
}
```