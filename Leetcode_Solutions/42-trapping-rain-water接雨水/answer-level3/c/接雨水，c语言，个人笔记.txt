### 解题思路
时间O(n) 空间O(1) 
找到最大值，双指针从两头往最大值遍历，如果下一个数比桶边低，说明可以接到水。

### 代码

```c
int trap(int* height, int heightSize){
    if(heightSize<1){
        return 0;
    }
    int max=0,result=0,temp=height[0];
    for(int i=1;i<heightSize;i++){
        if(height[i]>height[max]){
            max = i;
        }
    }
    for(int i=1;i<max;i++){
        if(height[i]<temp){
            result += temp-height[i];
        }else{
            temp = height[i];
        }
    }
    temp = height[heightSize-1];
    for(int j=heightSize-2;j>max;j--){
        if(height[j]<temp){
            result += temp-height[j];
        }else{
            temp = height[j];
        }
    }
    return result;
}
```