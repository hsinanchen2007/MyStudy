加这句
if(len % 2) 
    return false;

```
bool judgeCircle(char * moves){
    int i = 0, j = 0;   
    int len = strlen(moves);

    int k;

    if(len % 2) 
        return false;
    for(k = 0; k < len; k++) {
        switch(moves[k]) {
            case 'U':
                i++;
                break;
            case 'D':
                i--;
                break;
            case 'L':
                j++;
                break;
            case 'R':
                j--;
                break;
        }
    }
    
    if(!i && !j) {
        return true;
    }
    return false;
}
```
