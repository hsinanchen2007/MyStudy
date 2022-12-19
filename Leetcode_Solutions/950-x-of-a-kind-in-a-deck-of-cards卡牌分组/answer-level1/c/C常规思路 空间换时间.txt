### 解题思路
用一个数组统计个数 然后穷举公约数即可

### 代码

```c
bool hasGroupsSizeX(int* deck, int deckSize){
    if(deckSize<2) return false;            
    if(deckSize==2&&deck[0]!=deck[1]) return false;
    int *temp=(int *)malloc(10000*sizeof(int)),i;
    for(i=0;i<10000;i++){           //置零
        temp[i]=0;
    }
    for(i=0;i<deckSize;i++){        //统计各个数字的小计
        temp[deck[i]]++;
    }
    int j;
    for(i=2;i<100;i++){             //穷举公约数
        for(j=0;j<10000;j++){
            if(temp[j]&&temp[j]%i!=0) break;
        }
        if(j==10000) return true;   //判断是否为所有小计的公约数
    }
    return false;
}
```