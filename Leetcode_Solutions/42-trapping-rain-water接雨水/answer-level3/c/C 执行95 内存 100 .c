### 解题思路


### 代码

```c
int trap(int* height, int heightSize){
    if(!heightSize) return 0;
    int max=0;
    for(int i=1;i<heightSize;i++){
        if(height[max]<height[i]) max=i;
    }
    int temp=0,count=0;
    for(int j=1;j<max;j++)    //从左开始 大换小加
        if(height[j]>height[temp]) temp=j;
        else count+=height[temp]-height[j];
    temp=heightSize-1;   
    for(int k=heightSize-2;k>max;k--)   //从右开始 大换小加
        if(height[k]>height[temp]) temp=k;
        else count+=height[temp]-height[k];   
    return count;
}
```