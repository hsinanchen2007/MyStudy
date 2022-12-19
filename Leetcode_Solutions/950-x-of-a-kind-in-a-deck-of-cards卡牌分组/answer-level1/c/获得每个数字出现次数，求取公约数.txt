
### 代码

```c
bool hasGroupsSizeX(int* deck, int deckSize){
    int gcd(int a,int b);
    int hash[10001]={0};
    int i,min,k;
    for(i=0;i<deckSize;i++){
        hash[*(deck+i)]++;
    }
    for(i=0;i<deckSize;i++){
        if(hash[*(deck+i)]==1){
            return false;
        }
        if(hash[*(deck+i)]!=0){
            min=hash[*(deck+i)];
        }
    }
    for(i=0;i<deckSize;i++){
        if(hash[*(deck+i)]!=0&&min>hash[*(deck+i)]){
            min=hash[*(deck+i)];
        }
    }
    k=min;//加快求取公约数
    for(i=0;i<deckSize;i++){//求取最小公约数
        k=gcd(k,hash[*(deck+i)]);
    }
    if(k>=2) return true;//最小公约数大于2
    else return false;
}

int gcd(int a,int b){//求取公约数
    int r=a%b;
    while(r!=0){
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}



```