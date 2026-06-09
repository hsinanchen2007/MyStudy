### 解题思路
![图片.png](https://pic.leetcode-cn.com/61005ee057c4f7a842f8b7e601ec070e9e42a150bcc877cf900fe012cc75d635-%E5%9B%BE%E7%89%87.png)

找出A、B中小的一个在进行递归，方便递归，减少递归次数。

### 代码

```java
class Solution {
    public int multiply(int A, int B) {
     if(A>B){
    int temp=A;
    A=B;
    B=temp;
     }
     
    if(A==0) return 0;
    return B+multiply(A-1,B);
    }
}
```