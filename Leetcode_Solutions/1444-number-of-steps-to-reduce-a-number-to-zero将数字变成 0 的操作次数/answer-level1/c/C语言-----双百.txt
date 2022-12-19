### 解题思路
此处撰写解题思路

### 代码

```c
int numberOfSteps (int num){
int count=0;
while(num){
    if(!(num%2)){
        num=num/2;
    }else{
        num=num-1;
    }
    count++;
}
return count;
}
```