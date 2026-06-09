### 解题思路
因为若是二进制的幂次方那么二进制形式就只能有一个1；
![image.png](https://pic.leetcode-cn.com/b82806aee1efc5f7ac264e870e5a58b9d2911fde164838dee498997b9ceb0e54-image.png)

### 代码

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0) return false;
        int res=0;
        while(n!=0){
            n=n&(n-1);
            res++;
            if(res>1){
                return false;
            }
        }
        return res==1;
    }
};
```