### 解题思路
遍历height，按下标一列一列求积水，再加和。
能写出来我就很满意了，所以效率比较低下。
执行用时 :116 ms, 在所有 C 提交中击败了12.95%的用户
内存消耗 :5.9 MB, 在所有 C 提交中击败了100.00%的用户

### 代码

```c
int trap(int* height, int heightSize){
    int i,j,waternum=0,maxleft=0,maxright=0;
    for(i=1;i<heightSize-1;i++){//对height中可能出现积水的下标进行遍历
        maxright=0;//每一轮将右边的墙初始化，左边墙用不着。
        if(maxleft<height[i-1])//对当前下表height数组左边的墙进行遍历找出最大的墙   (按下面的写法会超出时间限制，不能用for了，左边的墙只需要考虑新出的墙是不是最大就行了，右边的墙每次都会少一块，所以不知道最大值了)
            maxleft=height[i-1];
        for(j=i+1;j<heightSize;j++){//对当前下表height数组右边的墙进行遍历找出最大的墙
            if(maxright<height[j])
                maxright=height[j];
        }
        if(height[i]>=maxleft||height[i]>=maxright){//如果当前下标的墙比左边右边的墙都大或者相等，那么不会有积水
            continue;
        }
        else {//其他情况都会有水，那边的最大墙的值最小，就用那边的墙高减去当前墙高得出积水
            if(maxleft>maxright){
                waternum=waternum+maxright-height[i];
            }
            else{
                waternum=waternum+maxleft-height[i];
            }
        }
    }
    return waternum;
}
```