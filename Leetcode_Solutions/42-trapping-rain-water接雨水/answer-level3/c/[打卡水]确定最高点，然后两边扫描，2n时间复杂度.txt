### 解题思路
1.找到最高点MAX
2.扫描从0到最高点MAX的区域，记下已扫描的区域的最高点A，那么对于位置i能够储存的水量为A的高度减去i的高度。

实际上，就是先保证水槽的一边不会漏水，然后看另一边的短板在哪儿，这个区域（A到MAX）的水位一定和短板的高度一致。

### 代码

```c
int trap(int* height, int heightSize){
int i,maxi,maxtmp,sum;
maxi=0;sum=0;
for(i=0;i<heightSize;i++){
    maxi=(height[i]>height[maxi])?i:maxi;
}
maxtmp=0;
for(i=0;i<maxi;i++){
    if(height[i]>height[maxtmp]) maxtmp=i;
    else sum+=(height[maxtmp]-height[i]);
    // printf("(%d,%d)",sum,i);
}
maxtmp=heightSize-1;
for(i=heightSize-1;i>maxi;i--){
    if(height[i]>height[maxtmp]) maxtmp=i;
    else sum+=(height[maxtmp]-height[i]);
    // printf("(%d,%d)",sum,i);

}
return sum;
}
```