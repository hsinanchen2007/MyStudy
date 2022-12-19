### 解题思路
双指针low、high，容积由两端较短的一方和宽len决定,当指针移动的时候，宽len会减少，当移动长的一端时容积只会更小，当移动短的一端时才有可能让容积变大。

### 代码

```c
int maxArea(int* height, int heightSize){
    if(heightSize<2){
        return 0;
    }
    int len=heightSize-1,low=0,high=heightSize-1,max=0;
    while(low<high){
        if(height[low]<=height[high]){
            if(height[low]*len>max){
                max = height[low]*len;
            }
            low++;
        }else{
            if(height[high]*len>max){
                max = height[high]*len;
            }
            high--;
        }
        len--;
    }
    return max;
}
```