### 解题思路
官方解题思路，应该注意的点都写在注释里

### 代码

```c
bool isPalindrome(int x){
        if(x<0)return false;//小于0的数不是回文
        if(x%10==0&&x!=0)return false;//10,100...都不是回文，但0是
        if(x==0)return true;
        int rnumber=0;//rnumber是反转后半部分的数
        while(x>=rnumber*10){//重点在这，判断已经处理了一半
            rnumber=rnumber*10+x%10;
            x=x/10;

        }
        
        if(rnumber==x||rnumber/10==x)return true;
       
        return false;
}
```