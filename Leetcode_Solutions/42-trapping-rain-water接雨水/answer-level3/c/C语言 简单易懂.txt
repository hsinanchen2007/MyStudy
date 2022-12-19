    思路简单代码也简单，可惜花费时间 4 ms算不上快。
    首先遍历一遍算出所有柱子的总和 sumS ；
    然后遍历第二遍，采用双指针按高度累计出所有柱子加水的和 sumW:
    比如题目描述给的图————高度为1的柱子加水有11个，高度为2一共为8，高度3是1，总和为20；
    最后(sumW-sumS)就是水的个数：例如途中柱子和 sumS=14,答案就是 20-14=6；
```


int trap(int* height, int heightSize){
    if(heightSize<=2)
        return 0;
    
    int sumW=0,sumS=0;
    int l=0,h=heightSize-1;
    int i=1;
    int t=0;
    while(t<heightSize)
    {
        sumS+=height[t];
        t++;
    }
    while(l!=h)
    {
        while(height[l]<i&&l<h)
            l++;
        while(height[h]<i&&h>l)
            h--;
        
        if(l!=h)sumW+=h-l+1;
        else sumW+=height[l]-i+1;
        
        i++;
    }
    
    return sumW-sumS;
}


```
