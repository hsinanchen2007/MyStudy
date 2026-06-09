一个从前往后找的解法，分析清楚后思路就比较简单了。

先上代码：
```cpp
vector<int> prevPermOpt1(vector<int>& A) {
    int left = 0, right = 0;
    for (int i = 0; i < A.size() - 1; i++)
    {
        if (A[i] > A[i+1])
        {
            left = i;
            right = i + 1;
        }
        else if (left != right && A[i] < A[i + 1] && A[left] > A[i + 1])
        {
            right = i + 1;
        }
    }
    
    swap(A[left], A[right]);
    
    return A;
}
```
从前往后查找，发现数据**变小**时记录下来`left`和`right`，后续如果有数据**变大**并且不大于`left`，更新`right`即可。示意如下：

![Description.png](https://pic.leetcode-cn.com/2fab07dc068d8549059d4ba1a6d38043043bdacb9b94764ee1e5ce9097ca7e99-Description.png)


