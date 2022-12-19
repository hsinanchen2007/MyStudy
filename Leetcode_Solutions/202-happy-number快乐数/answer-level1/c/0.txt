### 解题思路
此处撰写解题思路

### 代码

```c
bool isHappy(int n){
int i,s=n;
while(s!=1&&s!=4){            //变成4就会进入不快乐的循环
n=s; s=0;
while(n){
    i=n%10;
    s+=i*i;
    n/=10;
} 
}
if(s==1) return true;
else return false;
}
```