### 解题思路
嵌套遍历，跟选择排序的过程一样。执行用时惨不忍睹。

### 代码

```c
int maxArea(int* height, int heightSize){
    if(heightSize==0||heightSize==1) return 0;
    int i=0,j=0,b=0,h=0,v=0;
    for(i=0;i<heightSize-1;i++){
        for(j=i+1;j<heightSize;j++){
            b=j-i;
            h=height[i]<height[j]?height[i]:height[j];
            v=v>b*h?v:b*h;
        }
    }
    return v;
}
```