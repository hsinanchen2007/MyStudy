### 解题思路
首先统计数组中数出现的次数，
之后，求它们的最大公约数，并判断其是否大于2.

### 代码

```c
#define min(a,b) a<b?a:b
int takegys(int x,int y){
    if(x<y){
        y=x+y;
        x=y-x;
        y=y-x;
    }
    do{
        int temp=x%y;
        x=y;
        y=temp;
    }while(y!=0);
    return x;
}
bool hasGroupsSizeX(int* deck, int deckSize){
    int count[10000]={0};
    for(int i=0;i<deckSize;i++){
        ++count[deck[i]];
    }
    int first=0;
    int gys=0;
    for(int i=0;i<10000;i++){   //search a non-zero number
        if(count[i]!=0){
            first=i;
            gys=count[first];
            break;            
        }
    }
    for(int i=first;i<10000;i++){
        if(count[i]!=0){
            gys=takegys(count[i],gys);            
        }
    }  
    return gys>=2;
}
```