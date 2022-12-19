### 解题思路
此处撰写解题思路

### 代码

```c
char * convertToTitle(int n){
    char *arr=(char*)malloc(10*sizeof(char));
    int i,j=8;
    for(i=0;i<10;i++){
        arr[i]='\0';
    }
    while(n!=0){
        n--;
        i=n%26;
        n=n/26;
        arr[j]=i+'A';
        j--;
    }
    return arr+j+1;
}
```