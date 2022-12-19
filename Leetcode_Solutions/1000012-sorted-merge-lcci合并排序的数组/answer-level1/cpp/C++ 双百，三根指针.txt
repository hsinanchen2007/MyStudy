### 解题思路
在 $A$ 的尾部有 `B.szie()` 个 $0$，那么可以考虑将 $A$ 和 $B$ 中最大的元素依次从后向前填满这些零，最终 $0$ 位全部被填满，合并完成。

自己制作了一个小视频演示一个典型案例：
![演示文稿1.mp4](04bf9ded-b675-42e0-91e1-61b8331ccd84)

### 代码

```cpp [-C++]
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int last_zero=A.size()-1;
        int B_last=n-1;
        int A_last=m-1;
        while(B_last>=0)
        {
            if(A_last<0)
            {
                A[last_zero]=B[B_last--];
                last_zero--;
            }
            else if(A[A_last]>=B[B_last])
            {
                A[last_zero]=A[A_last];
                last_zero--;
                A[A_last]=0;
                A_last--;
            }
            else
            {
                A[last_zero]=B[B_last--];
                last_zero--;
            }
        }
    }
};
```

### 速度
![image.png](https://pic.leetcode-cn.com/418004f25197668b06dd75ae3dc1a1559de6e2b23666806005c2ec7c966a0dd2-image.png)
