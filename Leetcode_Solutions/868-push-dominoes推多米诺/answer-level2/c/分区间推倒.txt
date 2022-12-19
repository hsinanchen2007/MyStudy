方法：遍历字符串，遇到'.'，增加计数，遇到R，记录这个R的位置并标记一个前置状态'R',判断上一个前置状态如果是R的话，从当前点往前将所有的'.'都刷成R；
如果是L则判断前置状态是L的话，从当前位置往前将所有的'.'刷成R，如果前置状态是R，则一半刷成L，一半刷成R

char * pushDominoes(char * dominoes){
    int midStand = 0;
    char preChar = '.';
    char *p1 = dominoes;
    char *p2 = dominoes;
    char *pR = dominoes;
    int i = 0;
    while(*p1){
        if(*p1 == '.'){
            midStand++;
        }
        if(*p1 == 'L'){
            switch (preChar){
                case '.':
                case 'L':
                    p2 = p1;
                    for(i = 0;i <midStand;i++){
                        p2--;
                        *p2 = 'L';
                    }
                    break;
                case 'R':
                    p2 = p1;
                    for(i = 0;i < midStand /2;i++){
                        p2--;
                        *p2 = 'L';
                    }
                    p2 = pR;
                    for(i = 0;i < midStand /2;i++){
                        p2++;
                        *p2 = 'R';
                    }
                    break;
            }
            preChar = 'L';
            midStand = 0;
        }
        if(*p1 == 'R'){
            pR = p1;
            if(preChar == 'R'){
                p2 = p1;
                for(i = 0;i <midStand;i++){
                    p2--;
                    *p2 = 'R';
                }
            }
            preChar = 'R';
            midStand = 0;
        } 
        p1++;
    }
    if((preChar == 'R')&& midStand){
        p2= pR;
        for(i = 0;i < midStand;i++){
            p2++;
            *p2 = 'R';
        }
    }
    return dominoes;
}