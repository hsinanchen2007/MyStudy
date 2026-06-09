### 解题思路
最后一个用例居然是1

### 代码

```c
bool checkPerfectNumber(int num){
    if(num<2){
        return false;
    }
    int sum=1,i=2;
    while(i*i<=num){
        if(num%i==0){
            if(i*i<num){
                sum+=(i+num/i);
            }else{
                sum+=i;
            }
        }
        i++;
    }
    return num==sum;
}
```