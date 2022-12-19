### 解题思路
此处撰写解题思路

### 代码

```c
int tribonacci(int n){
    if(n==0){
        return 0;
    }
    else if(n==1 || n==2){
        return 1;
    }
    int tn = 0,tn1 = 1,tn2 = 1;
    int result = 0;
    for(int i=3;i<=n;i++){
        result = tn+tn1+tn2;
        tn = tn1;
        tn1 = tn2;
        tn2 = result;
    }
    return result;
}
```