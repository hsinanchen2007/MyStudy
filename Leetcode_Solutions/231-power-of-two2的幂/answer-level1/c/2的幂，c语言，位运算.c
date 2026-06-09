### 解题思路
就是看这个数字二进制中只有一个位置上是1，消掉最后一个位置上的1的方法就是 n&n-1

### 代码

```c
bool isPowerOfTwo(int n){
    if(n<=0){
        return false;
    }
    if((n&n-1) == 0){
        return true;
    }else{
        return false;
    }
}
```