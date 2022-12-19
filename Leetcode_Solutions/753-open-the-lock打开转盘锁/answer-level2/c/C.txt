```
int strtoint(char *s){
    int res, i;
    for(i = 0, res = 0; i < 4; i++){
        res *= 10;
        res += s[i]-'0';
    }
    return res;
}

int openLock(char ** deadends, int deadendsSize, char * target){
    int array[10000];
    int qu[10000];
    int i, j, k, tmp, this;
    int aim = strtoint(target);
    for(i = 0; i <10000; i++)
        array[i] = -2;
    for(i = 0; i < deadendsSize; i++){
        tmp = strtoint(deadends[i]);
        if(tmp==0)
            return -1;
        array[tmp] = -1;
    }
    if(0 == aim)
        return 0;
    int tail = 1;
    int head = 0;
    int layer = 0;
    int size;
    int d[4];
    int out[4];
    qu[head] = 0;
    while(++layer <= 20 && tail != head){
        size = tail - head;
        for(i = 0; i < size; i++){
            tmp = qu[(head++)%10000];
            d[0] = tmp%10;d[1] = (tmp/10)%10;d[2] = (tmp/100)%10;d[3] = tmp/1000;
            for(j = 0; j < 4; j++){
                for(k = -1; k <= 1; k+=2){
                    out[0]=d[0];out[1]=d[1];out[2]=d[2];out[3]=d[3];
                    out[j] = (10 + d[j] + k) % 10;
                    this = out[0]+out[1]*10+out[2]*100+out[3]*1000;
                    if(this == aim)
                        return layer;
                    if(array[this] == -2){
                        qu[(tail++)%10000] = this;
                        array[this] = layer;
                    }
                }
            }
        }
    }
    return -1;
}
```
