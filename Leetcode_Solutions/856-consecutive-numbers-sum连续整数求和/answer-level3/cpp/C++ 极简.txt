#### 思路：
![image.png](https://pic.leetcode-cn.com/3df70e4ce7885a9f5eb6ec40e564d6cd2a4052384fd7e8dbf127da3984c613f6-image.png){:width=600}
#### 代码：
```C++ [-C++]
int consecutiveNumbersSum(int N) {
    int ans = 0;
    for (int i = 1; N > 0; N-=i, i++)
        ans += (N % i == 0);
    return ans;
}
```
