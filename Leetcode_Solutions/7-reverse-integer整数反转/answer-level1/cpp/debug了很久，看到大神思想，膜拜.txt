### 解题思路
之前的想法一直都是算出来后再比较，结果啊先总是执行错误。
后来看到大神的想法，错一位的时候进行比较的话，就不会出现越界的情况了。

### 代码

```cpp
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x != 0){
            int temp = x % 10;
            x = x / 10;
            //这里的精髓在于将其进行了判断,如果放在后面的话，可能会报错
            if(res > INT_MAX / 10) return 0;
            if(res < INT_MIN / 10) return 0;
            res = res * 10 + temp;

        }
        return res;
    }
};
```