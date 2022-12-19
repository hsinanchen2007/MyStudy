```
    int w[100010],stk[100010],tt;//栈内矩形向左最大延伸宽度 也可以理解为矩形合并成一个更宽的
    int largestRectangleArea(vector<int>& h) {
        int n = h.size(),ans = 0;
        tt = -1, h.push_back(0);//栈顶指针初始为-1 在高度数组的末尾增加一个最低的矩形为哨兵
        for(int i = 0; i <= n; i++){
            int width = 1;//当前矩形i向左能延伸的长度
            while(tt!=-1 && stk[tt] > h[i]){//右边发现了一个高度更小的矩形h[i]
                                            //则该矩形将阻断左边所有比它高的矩形
                                            //而它是单调栈 则栈顶元素比次栈顶元素要大 
                                            //所以栈顶矩形能延伸的最大左右边界
                                            //就都确定了[ stk[tt-1], h[i] ] 
                width += w[tt];//当前栈顶元素能向左右延伸的最大宽度
                ans = max(ans,width*stk[tt]);//计算以当前栈顶元素向左右延伸的最大面积
                tt--;
            }
            stk[++tt] = h[i], w[tt] += width;//当前矩形向左延伸的长度
        }
        return ans;
```
