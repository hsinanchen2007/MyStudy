
### 代码

```cpp
class Solution {
public:
    int findNthDigit(int n) {
        if (n < 10)  return n;//step 1
        long long length = 0, cnt = 9, i = 1;
        for (; length + cnt*i < n; ++i){//step 2
            length += cnt * i;
            cnt *= 10;
        }//step 3
        long long num = pow(10, i-1) + (n-length-1)/i; //从0开始
        long long index = (n-length-1)%i;
        return to_string(num)[index]-'0';
    }
};
```