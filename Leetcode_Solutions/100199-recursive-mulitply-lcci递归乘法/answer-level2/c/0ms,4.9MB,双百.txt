### 解题思路
多了一步判断，可以让速度快很多哈，虽然代码看起来一般，但效率其实是不错的

### 代码

```c
int multiply(int A, int B){
    if(A<B){
        int result=B;
        if(A-->1){
            result+=multiply(A,B);
        }
        return result;
    }
    else{
        int result=A;
        if(B-->1){
            result+=multiply(A,B);
        }
        return result;
    }  
}
```