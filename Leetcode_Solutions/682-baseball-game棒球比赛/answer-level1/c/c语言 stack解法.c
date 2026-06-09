**# 代码：**

```

int stoi(char *s);
int calPoints(char ** ops, int opsSize){
    
    int currentindex = 0, score = 0;
    int stack[1001], temp;
    
    for(int i = 0; i < opsSize; i++){
        if(!isalpha(ops[i][0]) && ops[i][0] != '+'){
            stack[currentindex] = stoi(ops[i]);
            score += stack[currentindex++]; 
        }
        else if (ops[i][0] == 'D'){
            stack[currentindex] = 2 * stack[currentindex-1];
            score += 2 * stack[(currentindex)-1];
            currentindex++;
        }else if (ops[i][0] == '+'){
            temp = stack[currentindex - 1] + (currentindex-2>=0 ?stack[currentindex -2]:0);
            stack[currentindex++] = temp;
            score += temp;
        }else if (ops[i][0] == 'C'){
            score -= stack[--currentindex];
        }

    }
    return score;
}


int stoi(char *s){
    int integer = 0, index = 0, sign = 1;
    while(s[index] != '\0'){
        if(s[index]  == '-'){
            sign = -1;
        }
        else{
        integer = integer * 10 + s[index] - '0';
        }
        index++;
    }
    return sign * integer;
}
```
