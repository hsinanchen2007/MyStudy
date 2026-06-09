### 解题思路
此处撰写解题思路
这个也算是参考别人的做法就是变乘变求余，最后求解。和上一个一样，最后n只会是2或者4或者3对应的上一个的余数是012三种情况。
### 代码

```cpp
class Solution {
public:
    int cuttingRope(int n) {
       
        if (n<4)
        return n-1;
        long result=1;
        while(n>4)
        {
            result*=3;
            result%=1000000007;
            n-=3;



        }
       return result*n%1000000007;



    }
};
```