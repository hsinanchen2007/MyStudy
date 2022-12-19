### 解题思路
这个题其实关键就算两个量：1、糖果种类数；2、糖果总个数的一半；
然后就只有两种情况：
1、糖果种类数不大于糖果总个数的一半，那就可以得到所有种类的糖果；
2、糖果种类数大于糖果总个数的一半，那就只能每种糖果最多选一个，最多能获取的种类数就是糖果总数的一半。

### 代码

```c
int cmp(const void* a,const void* b){
    if(*(int*)a<*(int*)b){
        return -1;
    }
    else if(*(int*)a==*(int*)b){
        return 0;
    }
    else{
        return 1;
    }
}

int distributeCandies(int* candies, int candiesSize){
    if(candies==NULL||candiesSize==0){
        return 0;
    }
    qsort(candies,candiesSize,sizeof(int),cmp);
    int typeCount = 1;
    int halfOfCount = candiesSize/2;
    for(int i=1;i<candiesSize;i++){
        if(candies[i]!=candies[i-1]){
            typeCount++;
        }
    }
    if(typeCount<=halfOfCount){
        return typeCount;
    }
    else{
        return halfOfCount;
    }
}



```