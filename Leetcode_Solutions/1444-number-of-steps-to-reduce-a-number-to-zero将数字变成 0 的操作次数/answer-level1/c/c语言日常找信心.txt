### 解题思路
没有思路

### 代码

```c
int numberOfSteps (int num){
    int temp=0;
    while(num!=0){
        if(num%2==0){
            num/=2;
            temp++;
        }
        else{
            num-=1;
            temp++;
        }
    }
    return temp;
}
```