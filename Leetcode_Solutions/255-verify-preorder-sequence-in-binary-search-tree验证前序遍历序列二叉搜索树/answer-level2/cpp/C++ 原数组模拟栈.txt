![image.png](https://pic.leetcode-cn.com/5d73679cd8f3fe37d03e0f4b7d642c6763582dd8938ff9cb757dc1f658c64a92-image.png)

```cpp
bool verifyPreorder(vector<int>& pre) {
  int k = -1, Min = INT32_MIN;
  for (auto val : pre) {
    if (val < Min) return false;
    while (k >= 0 && pre[k] < val) Min = pre[k--];
    pre[++k] = val;  //<复用原数组模拟栈,以优化内存
  }
  return true;
}
```

参考：https://blog.csdn.net/qq508618087/article/details/50929129