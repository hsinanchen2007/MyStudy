### 解题思路
解题思路

### 代码

```c
int calPoints(char ** ops, int opsSize){
    int arr[1000]={0};
    int score=0,i=0,j=0;
    while(i<opsSize){
        switch(ops[i][0]){
            case 'C':
                arr[j-1]=0;
                j-=2;
                break;
            case 'D':
                arr[j]=arr[j-1]*2;
                break;
            case '+':
                arr[j]=arr[j-1]+arr[j-2];
                break;
            default:
                arr[j]=atoi(ops[i]);
                break;
        }
        j++;
        i++;
    }
    for(i=0;i<j;i++){
        score+=arr[i];
    }
    return score;
}
```