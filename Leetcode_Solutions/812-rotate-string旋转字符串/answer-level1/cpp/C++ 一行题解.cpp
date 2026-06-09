### 代码

```cpp
class Solution {
public:
    bool rotateString(string A, string B) {
        return A.size() == B.size() && (A + A).find(B) != string::npos;
    }
};
```

![image.png](https://pic.leetcode-cn.com/efeaf2ab9b92dba9bbf56c1f0a531776fb8a897562f2f0c093b409f3634820c7-image.png)
