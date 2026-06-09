### 解题思路
先定义一个排序的规则，之后按照这个规则进行排序就OK

### 代码

```c
char * customSortString(char * S, char * T){
    int a[26]={0},i,t,k=1,j;
    char c;
    for(i=0;S[i]!='\0';i++){
        t=S[i]-'a';
        a[t]=k++;
    }
    for(i=0;T[i]!='\0';i++){
        k=i;
        for(j=i+1;T[j]!='\0';j++){
            if(a[T[j]-'a']<a[T[k]-'a']) k=j;
        }
        if(k!=i){
            c=T[i];
            T[i]=T[k];
            T[k]=c;
        }
    }
    return T;
}
```