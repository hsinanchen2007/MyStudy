![1f95a9f53714bf2c858a4096a44ca31.png](https://pic.leetcode-cn.com/cf0cb24edd5cf468d417834a3513e4d4a084feae418d8351d99a26dfea1ab3f1-1f95a9f53714bf2c858a4096a44ca31.png)

```

int trap(int* height, int heightSize){
    //无解情况
    if(heightSize==0){
        return 0;
    }
    //先找水池边界
    int left=0;
    int right=heightSize-1;
    for(left=0;left<heightSize;left++){
        if(height[left]!=0){
            break;
        }
    }
    for(right=heightSize-1;right>0;right--){
        if(height[right]!=0){
            break;
        }
    }
    //边界重合或者全为0，只有一柱子，存个锤子的水
    if(left>=right){
        return 0;
    }

    //定义最大值和最大值个数
    int max=0;
    //定义水池本身体积
    int self_vol=0;
    //找出最大值和水池本身体积,但水池还得先减去左右边界的体积
    for(int i=0;i<heightSize;i++){
        if(max<height[i]){
            max=height[i];
        }
        self_vol+=height[i];
    }
    self_vol-=(height[left]+height[right]);
    //让左边界和右边界之间充满水位最高的水
    int water=(right-left-1)*max;
    //记录当前遇到的柱子最高的，但小于最高的柱子，左右都能用
    int cur_max=height[left];
    //左边缘不是最高的柱子，就可以往右走，依次把水放掉，直到遇见最高的柱子
    while(height[left]!=max){
        //如果右边相邻柱子比当前左边最高柱子高，直接放水
        if(cur_max<=height[left+1]){
            water-=(max-height[left+1]);
            left++;
            cur_max=height[left];
        }
        //如果比当前低，则放到当前左边最高水位
        else{
            water-=(max-cur_max);
            left++;
        }

    }
    //右边缘不是最高的柱子，就可以往左走，依次把水放掉，直到遇见最高的柱子
    cur_max=height[right];
    while(height[right]!=max){
        //如果左边相邻柱子比当前右边最高柱子，直接放水
        if(cur_max<=height[right-1]){
            water-=(max-height[right-1]);
            right--;
            cur_max=height[right];
        }
        //如果比当前低，则放到当前左边最高水位
        else{
            water-=(max-cur_max);
            right--;
        }
    }
    return water-self_vol;
}
```