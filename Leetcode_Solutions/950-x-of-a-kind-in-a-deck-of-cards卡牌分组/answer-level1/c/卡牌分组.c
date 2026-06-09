### 解题思路


### 代码

```c
int gcd(int a,int b){
    return b ? gcd(b,a%b) : a;
}
bool hasGroupsSizeX(int* deck, int deckSize){
    int hash[10000] = {0};
    int i,g = -1;
    for(i = 0;i < deckSize;i++) hash[deck[i]]++;
    for(i = 0;i < 10000;i++){
        if(hash[i]){
            if(g == -1)
                g = hash[i];
            else
                g = gcd(g,hash[i]);
        }
    }
    return g > 1 ? true : false;
}

```