### 虽然做不到官方那么厉害，但是这是自己写的。。
思路很简单，取除9的余数，但是9的倍数需要另外考虑
1.num=0,直接返回0
2.num=9k(k>0),和必为9，证明很简单（9的倍数的各位和依然是9的倍数，无穷递降一下就行）
3.非9的倍数，那就直接取余数吧

### 代码

```java
class Solution {
    public int addDigits(int num) {
        if(num==0)return 0;
        if(num%9==0)return 9;
        return num%9;
    }
}
```