维护**非单调递减**的栈为什么可以解决问题？
首先，**以某个柱子A为高**（相对于X轴，矩形的高），画的矩形面积最大，就是找到柱子A两边比它矮的两个柱子，
这两个柱子不能用在矩形里面，因为如果用了，矩形就不能以A为高了。
```
public int largestRectangleArea(int[] heights) {
        Stack<Integer> stack=new Stack<> ();
        int maxArea =0;
        //push一个-1，为了防止左边界在整个数组左边也就是-1
        stack.push(-1);
        //最后一位为零来触发面积的计算
        int[] myHeights = new int[heights.length+1];
        System.arraycopy(heights, 0, myHeights, 0, heights.length);

        for(int i=0;i<myHeights.length;i++){
            while(stack.peek()!=-1&&myHeights[stack.peek()]>myHeights[i]){
                int cur=stack.pop();
                maxArea = Math.max(maxArea,(i-stack.peek()-1)*myHeights[cur]);
            }
            stack.push(i);
        }
        return maxArea;

    }
```

程序刚开始从左到右依次读取柱子的高，如果遇到比栈顶柱子index_i-1矮的柱子index_i，
说明对于栈顶柱子而言，它的右边界就已经找到了。

并且因为栈是非单调递减的，所以栈顶柱子index_i-1的左边界就是它左边相邻的几个（可能有等高的）。

while循环中，计算当前柱子index_i**之前**的柱子围成的最大面积，因为它矮，所以不会以它作为矩形的高。
那之前从0，1,2,3,4......i中，可能存在k，柱子index_k比index_i还要矮
注意0,1,2,...k这些柱子要保留在栈中，因为当前柱子index_i虽然它目前没有参与计算，但以后它要以index_k的柱子为左边界！
而k+1,k+2.....i-1这些柱子都比当前柱子index_i高，并且非单调递减。他们都以当前柱子index_i为右边界，以index_k为左边界。

对于这些比当前柱子高的这些柱子，来找出他们中矩形面积最大值。
找的方法[(右边界i)-(左边界stack.peek())-1]*Heights[cur]    cur就是当前想以它为高计算的柱子index_cur


虽然题目解题思想很直观，找到某个柱子的左右边界，但是想到维护一个非递减栈，就能这么巧妙的找到各个柱子的左右边界对我而言还是太难了。
想了好几个小时才彻底弄懂，羡慕powcai这样的大佬，太聪明了。



