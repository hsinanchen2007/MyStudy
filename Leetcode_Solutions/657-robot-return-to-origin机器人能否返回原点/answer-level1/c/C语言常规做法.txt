```c
bool judgeCircle(char * moves){
    int vertical=0,horizonal=0,i=0;
    while(moves[i]!=0){
        switch(moves[i]){
            case 'L':horizonal++;break;
            case 'R':horizonal--;break;
            case 'U':vertical++;break;
            case 'D':vertical--;break;
        }
        i++;
    }
    return (horizonal==0&&vertical==0);
}
```