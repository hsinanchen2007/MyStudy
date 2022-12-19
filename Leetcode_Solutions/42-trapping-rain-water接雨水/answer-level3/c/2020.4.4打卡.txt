### 解题思路
乘满水后的形状是从最高的柱子向两边下降的阶梯，
所以先找到最高的柱子，分别从两边低处向中间高处遍历，
每次找到阶梯的每一阶的两边的id，计算出这一个阶梯的长度，用长度*阶梯高度得出该阶梯的体积，再减去中间低柱子的体积，就得出该阶的水体积，
如此累加每一阶水的体积即可得到答案。
ps：注意样例为空的情况

执行用时 :4 ms, 在所有 C 提交中击败了95.25%的用户
内存消耗 :5.9 MB, 在所有 C 提交中击败了100.00%的用户

### 代码

```c
int trap(int* height, int heightSize){
    if(heightSize==0)
    {
        return 0;
    }
    int highest=0;
    int highest_id=0;
    for(int i=0;i<heightSize;i++) //找出最高点
    {
        if(highest<height[i])
        {
            highest=height[i];
            highest_id=i;
        }
    }

    int pre_id,cur_id;
    int ans=0;

    //从左向最高点遍历
    pre_id=0;
    while(pre_id<highest_id)
    {
        int stone=0;
        cur_id=pre_id+1;
        while(cur_id<heightSize && height[cur_id]<=height[pre_id] && cur_id<highest_id)
        {
            stone+=height[cur_id];
            cur_id++;
        }
        int len=cur_id-pre_id-1;
        int water=len*height[pre_id]-stone;
        ans+=water;

        pre_id=cur_id;
    }

    //从右向最高点遍历
    pre_id=heightSize-1;
    while(pre_id>highest_id)
    {
        int stone=0;
        cur_id=pre_id-1;
        while(cur_id>=0 && height[cur_id]<=height[pre_id] && cur_id>highest_id)
        {
            stone+=height[cur_id];
            cur_id--;
        }
        int len=pre_id-cur_id-1;
        int water=len*height[pre_id]-stone;
        ans+=water;

        pre_id=cur_id;
    }   

    return ans;
}
```