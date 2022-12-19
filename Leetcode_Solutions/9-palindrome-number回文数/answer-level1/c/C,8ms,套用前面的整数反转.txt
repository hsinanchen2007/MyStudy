### 解题思路
此处撰写解题思路

### 代码

```c
bool isPalindrome(int x){
    int temp=x;
    long int num=0;
 
    while(x>0)
    {
        num=num*10+x%10;
        x=x/10;
    }
    if(temp==num)     //8ms
        return true;
    else
        return false;
 //   return temp==num?true:false; //24ms

}
```