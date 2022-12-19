### 解题思路
模拟雨水高度从0往上涨的过程

### 代码

```c
int trap(int* height, int heightSize){
    int maxh=0,maxhi;
    if(heightSize==0||heightSize==1)
        return 0;
    for(int i=0;i<heightSize;i++){
        if(height[i]>maxh){
            maxh=height[i];//找出柱体中最高的那个
            maxhi=i;//记录下标
        }
    }
    int water_l=0;//雨水的高度
    int rain=0;//雨水总量
    for(int i=0;i<maxhi;i++){//从最左边遍历到最高点
        if(height[i]>water_l){//当前柱体高度高于雨水高度，则雨水高度涨到该柱体的高度
            water_l=height[i];
        }
        rain+=water_l-height[i];//雨水高度减当前柱体高度，即当前柱体上的雨水高度
    }
    water_l=0;
    for(int i=heightSize-1;i>maxhi;i--){//从最高点遍历到最左边
        if(height[i]>water_l){
            water_l=height[i];
        }
        rain+=water_l-height[i];
    }
    return rain;
}
```