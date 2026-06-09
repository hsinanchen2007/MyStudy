用i，j指向两端，每次移动高度最小的那个指针。
每次移动都判断是否因为移动而增多容量
这样子就只需要经过一次的线性遍历就可以找出最大容量。
```
int min(int a,int b)
{
    return a>b?b:a;
}
int maxArea(int* height, int heightSize){
    int i=0,j=heightSize-1,max=(j-i)*min(height[i],height[j]);//i,j分别指向两端
    while(j>i)
    {
        if(height[i]<height[j])
            i++;
        else
            j--;
        if(max<(j-i)*min(height[i],height[j]))
        max=(j-i)*min(height[i],height[j]);
    }
    return max;
}
```











