### 解题思路
首先设置一个二维标志数组arr，初始化为0.
当k=1时可知，输出必为1。 
开始递归遍历，需满足以下条件：1）访问该位置未越界； 2）满足：位数和 < k； 3）该位置没有被访问过（标志数组的该位置未修改过，为0），则将标志数组该位置置为1，计数器加一，否则，其他情况都直接返回。
本文按照上下左右顺序开始遍历。

### 由已知条件知道，m,n 都是在1-100之间，也就是最大数组位置也是两位数，即（99，99），因此判断位数和可以表示如下：i%10 + i/10 + j%10 + j/10 > k

### 代码

```cpp
class Solution {
public:
    int nums = 0;
    int movingCount(int m, int n, int k) {
        vector<vector <int> > arr(m, vector<int>(n, 0));
        if(k == 0)
            return 1;
        search(m, n, k, arr, 0, 0);
        return nums;
    }
    void search(int m, int n, int k, vector<vector <int> >& arr, int i, int j){
        if(i >= m || j >= n || i < 0 || j < 0)
            return;
        if(arr[i][j] == 1)
            return;
        if((i%10 + i/10 + j%10 + j/10) > k)
            return;
        arr[i][j] = 1;
        nums++;
        search(m, n, k, arr, i-1, j);
        search(m, n, k, arr, i+1, j);
        search(m, n, k, arr, i, j-1);
        search(m, n, k, arr, i, j+1);
    }
};
```