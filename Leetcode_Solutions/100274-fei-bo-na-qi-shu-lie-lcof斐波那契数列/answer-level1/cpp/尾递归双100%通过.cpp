### 解题思路
怀疑是不是服务器的运气问题，第一次双100%
思路大概是尾递归的Fib，然后第一次没注意溢出的问题，于是调整了一下就过了？就过了？？？
唯一要注意的就是v1和v2最开始对应第1和第2个斐波那契数，然后当v1/v2很大的时候，就取余，因为1000000007在我们的结果中完全不重要，超过它就删掉与最后一起求余没有区别

### 代码

```cpp
class Solution {
public:

    int tailFib(int n, long v1, long v2){
        if(n==0){
            return v1 % 1000000007;
        }
        else{
            if(v1>1000000007){
                return tailFib(n-1, v2%1000000007, (v1+v2)%1000000007);
            }
            return tailFib(n-1, v2, v1+v2);
        }
    }

    int fib(int n) {
        return tailFib(n, 0, 1);
    }
};
```