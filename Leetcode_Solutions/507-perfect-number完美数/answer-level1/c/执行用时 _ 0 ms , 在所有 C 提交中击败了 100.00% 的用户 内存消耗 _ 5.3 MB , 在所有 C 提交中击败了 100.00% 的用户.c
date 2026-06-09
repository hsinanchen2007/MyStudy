### 解题思路
遍历

### 代码

```c
bool checkPerfectNumber(int num){
    if(num==0){
        return false;
    }
    int sum=0;
    for(int i=1;i<sqrt(num);i++){
        if(num%i==0){
            sum+=i;
            if(i*i<num){
                sum+=num/i;
            }
        }
        
    }
    if(sum==num*2){
        return true;
    }else{
        return false;
    }
    return false;
}
```