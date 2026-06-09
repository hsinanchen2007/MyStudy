### 解题思路
我们strstr需要验证的范围明确后，就比较容易了，字符串A要repeat次数的范围是： 
最小判断范围： A * repeat  >=B
最大判断范围： A * repeat <= A+B
剩下的看代码就很容易了
### 代码

```c
int repeatedStringMatch(char * A, char * B){
    int cntA = strlen(A);
    int cntB = strlen(B);
    int ret= -1;
    char * strtmp;
    if (cntA >= cntB){
        strtmp = calloc(2*cntA +1, sizeof (char));
        memcpy(strtmp, A, cntA+1);
        if(NULL != strstr(strtmp,B)){
            ret = 1;
        } else {
            memcpy(strtmp+cntA,A,cntA+1);
            if(NULL != strstr(strtmp,B))
                ret = 2;
        }
    } else{ //A <B
        char * tmp;
        int step =(cntB%cntA ==0)? ((cntB/cntA)+1 ):((cntB/cntA)+2);
        strtmp = calloc(step*cntA +1,sizeof(char));
        tmp = strtmp;
        for(int i = 0; i<step-1;i++){
            if(i == (step -2) )
                memcpy(tmp,A,cntA+1);
            else
                memcpy(tmp,A,cntA);
            tmp = tmp +cntA;
        }
        if(NULL != strstr(strtmp,B)){
            ret = step -1;
        }else{
             memcpy(tmp,A,cntA+1);
              if(NULL != strstr(strtmp,B))
                    ret = step;
        }
 
    }
    free(strtmp);
    return ret;
}
```