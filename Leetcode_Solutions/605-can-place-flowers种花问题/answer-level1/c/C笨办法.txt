### 解题思路
此题难度在于边界判断，笨办法是分开用if讨论。

### 代码

```c
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
    if(flowerbedSize==0) return false;
    int count=0;
    if(flowerbedSize==1){//单元素数组
        if(flowerbed[0]==0) count++;
    }else if(flowerbedSize==2){//只有两元素
        if(flowerbed[0]==0&&flowerbed[1]==0) count++;
    }else{
        for(int i=0;i<flowerbedSize;i++){
            if(i==0){//第一个元素
                if(flowerbed[i]==0&&flowerbed[i+1]==0){
                    count++;
                    flowerbed[i]=1;//符合条件则种花，标记为1
                } 
            }else if(i==flowerbedSize-1){//最后一个元素
                if(flowerbed[i]==0&&flowerbed[i-1]==0){
                    count++;
                    flowerbed[i]=1;
                } 
            }else{
                if(flowerbed[i]==0){
                    if(flowerbed[i-1]==0&&flowerbed[i+1]==0){
                        count++;
                        flowerbed[i]=1;
                    }
                }
            }
        }
    }
    
    return count<n?false:true;
}
```