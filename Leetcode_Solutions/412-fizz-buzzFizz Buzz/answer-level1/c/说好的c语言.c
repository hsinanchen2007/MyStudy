```
char ** fizzBuzz(int n, int* returnSize){
    *returnSize =n;
    char** res = (char**)malloc(sizeof(char*)*n);
    char temp[10] = {0};
    
    for(int i=1;i<=n;i++) {
        if(i%3==0&&i%5==0) {
            sprintf(temp, "%s", "FizzBuzz");
        } else if(i%3==0) {
            sprintf(temp, "%s", "Fizz");
        } else if(i%5==0) {
            sprintf(temp, "%s", "Buzz");
        } else {
            sprintf(temp, "%d", i);
        }
        
        res[i-1] = (char*)malloc(strlen(temp)+1);
        strcpy(res[i-1], temp);
        memset(temp, 0, 10);
    }
    
    return res;
}

```
