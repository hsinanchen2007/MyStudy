### 解题思路
暴力破解法
### 代码

```c
int min(int a,int b){
    return a<b?a:b;
}
int maxArea(int* height, int heightSize){
    int max=0;
    int p;
    for(int i=0;i<heightSize-1;i++)
        for(int j=i+1;j<heightSize;j++){
            p=min(height[i],height[j])*(j-i);
            if(p>max)
                max=p;
        }
    return max;
            
    
}
```