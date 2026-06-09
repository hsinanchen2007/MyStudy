```
    /*
    单调栈 当后者高度大于前者时 则前者对后面的雨水计算无用 因为之后的计算都会因后者更高而隔开 
          因此可以弹出前面这些小的高度  也就是建立一个单调减少的栈
          在弹出过程中 会出现凹槽(左大 中小 右大) 每次弹出时计算该凹槽的面积即可
    */
    int trap(vector<int>& h) {
        int res = 0,tt = -1;
        vector<int> s(h.size());//单调栈 tt为栈顶 栈内存储的是在h中的下标 这样方便计算宽度
        for(int i = 0; i < h.size(); i++){
            while(tt!=-1&&h[i] > h[s[tt]]){
                int low = h[s[tt--]];//凹槽底部的高度
                if(tt==-1) break;
                res += (i-s[tt]-1)*(min(h[s[tt]],h[i])-low);//由h[s[tt]] low  h[i] 组成的凹槽 计算面积
            } 
            s[++tt] = i;
        }
        return res;
    }
```
