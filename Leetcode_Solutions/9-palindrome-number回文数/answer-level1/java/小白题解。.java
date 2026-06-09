### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
    int a=x;//防止下面的while循环将x的值改变
    boolean b=false;
    if(x<0)
    {
        b=false;
    }
    else
    {int res=0;
     while(x!=0)
     { res=res*10+x%10;
       x=x/10;
     }
     if(res==a)
     { b=true;
     }
    }
    return b;
    }
}
```