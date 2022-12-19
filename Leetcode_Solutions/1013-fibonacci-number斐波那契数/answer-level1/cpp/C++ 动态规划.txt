### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/f6686e028a976574e225debbf498f45f3439e7ba67ea77fa3459847379063a7e-image.png)

### 代码

```cpp
class Solution {
public:
    int fib(int N) {
        if(N == 0)
            return 0;
        int temp[N+1];
        temp[0] = 0;
        temp[1] = 1;
        for(int i =2;i<N+1;i++)
            temp[i] = temp[i-1] + temp[i-2];
        return temp[N];
    }
};
```