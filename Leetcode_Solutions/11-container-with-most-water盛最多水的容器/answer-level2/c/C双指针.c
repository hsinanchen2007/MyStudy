### 解题思路
抄了一遍官方的解法。
![捕获.PNG](https://pic.leetcode-cn.com/40d472a39924091534caa49a7a165ed061787cc4237427367607f2baa4684b1d-%E6%8D%95%E8%8E%B7.PNG)

### 代码

```c
int maxArea(int* height, int heightSize){
    if(heightSize==0||heightSize==1) return 0;
    int *p=&height[0],*q=&height[heightSize-1],h=*p<*q?*p:*q,b=heightSize-1,v=b*h;
    while(heightSize-2){
        --b;
        if(h==*p){
            ++p;
        }else{
            --q;
        }
        h=*p<*q?*p:*q;
        v=v>b*h?v:b*h;
        --heightSize;
    }
    return v;
}
```