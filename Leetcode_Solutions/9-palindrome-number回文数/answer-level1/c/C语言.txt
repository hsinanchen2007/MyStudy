### 解题思路
此处撰写解题思路 怎么简单的题都不会 很菜！

### 代码

```c
bool isPalindrome(int x){
    // if ( x < 0) return false;
    // //if ( x >= 0 && x < 10 ) return true;
    // //if ( (x % 10) == 0 ) return false;

    // long res = 0 ;
    // int tmp = x;
    // while ( x != 0){
    //     res = 10 * res + ( x % 10);
    //     x = x / 10;
    // }
    // if (res == tmp ) return true;
    // return false;
    long y = 0;
    int z = x;
    if(x<0) return false;
    while(x!=0){
        y=y*10 + (x%10);
        x = x/10;
    }
    if(y==z){
        return true;
    }else{
        return false;
    }


}
```