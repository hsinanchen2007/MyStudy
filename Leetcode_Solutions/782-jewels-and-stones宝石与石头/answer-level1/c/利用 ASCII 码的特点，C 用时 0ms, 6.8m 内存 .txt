啥都不说了，上码  

```c   
int numJewelsInStones(char * J, char * S){
    if(!J || !S ) {
        return 0;
    }
    int arr[58]={0};
    int count = 0;
    for(int i = 0; i < strlen(J); i ++) {
        arr[(int)J[i]-65]=1; 
    }
    for(int j = 0; j < strlen(S); j ++) {   
        if(arr[ (int)S[j]-65] == 1) {
            count ++;
        }
    }
    return count;
}    
```
