### 解题思路
超级简单的思路
拷贝一份数据，
再制作一个回转的数据，
如果两个数据比对一样，那么就true。
### 代码

```c
bool isPalindrome(int x){
    long a = x,count = 0;
    if(x < 0)
        return false;
    while(x){
        count = count*10 + x%10;
        x = x/10;
    }
    if(count == a){
        return true;
    }
    return false;
}
```