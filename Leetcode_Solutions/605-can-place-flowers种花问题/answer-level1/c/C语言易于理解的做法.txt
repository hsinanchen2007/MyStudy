为了统一，假设给定数组左边还有[1,0]，右边还有[0,1]，记在心里即可，不需要更改或重新构建数组。假设两个1之间有gap个0，那么这两个1之间可以种的花的数目为(gap-1)/2，可以中的花的总数大于或等于n，则返回true。
```c
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
    short gap=1,i;
    for(i=0;i<flowerbedSize;i++){
        if(flowerbed[i]==0) gap++;
        else{
            n=n-(gap-1)/2;
            gap=0;
        }
    }
    if(gap!=0) n=n-gap/2;
    return n<=0;
}
```