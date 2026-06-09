### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int fib(int n) {
        if(!n)
            return 0;
        int prepre = 0;
        int pre = 1;
        int index = 1;
        int cur ;
        while(index<n){
            cur = (pre + prepre)% 1000000007;
            prepre = pre;
            pre =cur;
            index++;
        }
        return pre;
    }
};
```