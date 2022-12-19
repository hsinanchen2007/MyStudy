### 解题思路
一开始是想要放在数组里的，后来想到不如直接就求和好了

### 代码

```c
bool isPalindrome(int x){
    if(x<0){
        return false;
    }
    int k=x;
    long long sum=0,i=0;
    do{
        sum=sum*10+k%10;
        k/=10;
    }while(k!=0);
    if(sum==x){
        return true;
    }
    return false;
}
```