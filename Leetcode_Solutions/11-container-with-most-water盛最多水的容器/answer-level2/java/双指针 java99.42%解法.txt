双指针解法，在头尾节点各定义一个指针，计算完当前容量后，对比左右两个指针，将值较小的指针往中间移动。
如果下一个节点的值比当前值小，那容量肯定小于当前的容量，所以不需要再去计算一遍，所以可以接着往下，直到找到比当前节点值大的节点，可以节约很多时间。
java实现如下
```
class Solution {
    public int maxArea(int[] height) {
        int l=0;
        int r=height.length-1;
        int res=0;
        while(l<r){
            res=Math.max(res,Math.min(height[l],height[r])*(r-l));
            int nowL=height[l];
            int nowR=height[r];

            //找到下一个比当前元素大的节点
            if(nowL<=nowR)
                while(++l < r && height[l] <= nowL) {}
            if(nowL>=nowR)
                while(l < --r && height[r] <= nowR) {}
        }
        return res;
    }
}

```
