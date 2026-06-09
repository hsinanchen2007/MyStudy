### 解题思路
- tmp保存N作为临时变量,
- res每次左移一位，最后要减1[减1后才是真正的对应的二进制]
- 进行异或运算就是结果
### 代码

```java
class Solution {
    public int bitwiseComplement(int N) {
        if(N ==0) return 1;
       int tmp = N;
        int res =1;
        while (tmp > 0) {
            tmp >>= 1;
            res <<=1;
        }
        return N ^ (res-1); 
    }
}
```