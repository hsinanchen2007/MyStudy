```
/**
 * 四种运算符，只有两种优先级，+ -运算符优先级低于 * /运算符,并且运算方向都是从左到右。
 * 遍历整个字符串，遇到数字则先存起来，遇到+则不处理，遇到-则将下一个数字转为负数再存起来。
 * 遇到*或者/运算法，则将上一个结果与下一个数字进行运算，然后把结果存起来。
 */

int getVal(char* s, int* pos){ //获取下一个值或符号  符号用负数代替  结束返回-1
    while(s[*pos] != '\0' && s[*pos] == ' '){
        (*pos)++;
    }
    
    if(s[*pos] == '\0'){
        return -1;
    }
    
    switch(s[*pos]){
        case '+': (*pos)++; return -2;
        case '-': (*pos)++; return -3;
        case '*': (*pos)++; return -4;
        case '/': (*pos)++; return -5;
        default: break;
    }
    
    int start = *pos;
    while(s[*pos] >= '0' && s[*pos] <= '9'){
        (*pos)++;
    }
    
    char temp = s[*pos];
    s[*pos] = '\0';
    
    int val = atoi(s+start);
    
    s[*pos] = temp;

    return val;
}

int calculate(char * s){
    int buf[65536 * 8], size = 0;
    int pos = 0, val, val1, val2;
    
    while(true){
        val = getVal(s, &pos);
        if(val == -1){
            break;
        }else if(val >= 0){//如果是一个数值，将数值存在buf中
            buf[size++] = val;
        }else if(val ==  -3){//如果是-运算法  那么获取下一个数值, 并将数值变为负数, 结果存在buf中
            buf[size++] = -getVal(s, &pos);
        }else if(val == -4){//如果是*运算法  那么获取下一个数值并与上一个数字相乘，结果存在buf中
            val1 = buf[--size];
            val2 = getVal(s, &pos);
            buf[size++] = val1 * val2;
        }else if(val == -5){//如果是/运算法  那么获取下一个数值并与上一个数字相乘，结果存在buf中
            val1 = buf[--size];
            val2 = getVal(s, &pos);
            buf[size++] = val1 / val2;
        }
    }
    
    int res = 0;
    for(int i = 0; i < size; i++){
        res += buf[i];
    }
    
    return res;
}
```
