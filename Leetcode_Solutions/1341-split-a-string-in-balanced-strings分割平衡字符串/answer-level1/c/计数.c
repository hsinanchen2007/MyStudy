### 解题思路


### 代码

```c
int balancedStringSplit(char * s){
    int sum = 0,cnt = 0;
    for(int i = 0;i < strlen(s);i++){
        if(s[i] == 'R') cnt ++;
        if(s[i] == 'L') cnt --;
        if(cnt == 0) sum++;
    }
    return sum;
}


```