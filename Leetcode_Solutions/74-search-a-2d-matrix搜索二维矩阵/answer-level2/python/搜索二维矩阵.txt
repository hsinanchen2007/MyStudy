
   
#### 方法：二分查找

**直觉**

注意到输入的 `m x n` 矩阵可以视为长度为 `m x n`的有序数组。

![二分查找](https://pic.leetcode-cn.com/d9b47b40a4de17b0c56446b0a4935a5042490ea1d92a6f4c529c2aaa0095c189-287711dcb87bd4d4681fa117f792d1baaaa7ce3e2c65d6a4f6439c0cbbb0345e-image.png){:width="550px"}
{:align=center}

由于该 _虚_ 数组的序号可以由下式方便地转化为原矩阵中的行和列 (_我们当然不会真的创建一个新数组_) ，该有序数组非常适合二分查找。

> `row = idx // n` ， `col = idx % n`。

**算法**

这是一个标准二分查找算法 : 

* 初始化左右序号 
`left = 0` 和 `right = m x n - 1`。

* While `left < right` :

    * 选取虚数组最中间的序号作为中间序号: `pivot_idx = (left + right) / 2`。
    
    * 该序号对应于原矩阵中的 `row = pivot_idx // n`行 `col = pivot_idx % n` 列, 由此可以拿到中间元素`pivot_element`。该元素将虚数组分为两部分。
    
    * 比较 `pivot_element` 与 `target` 以确定在哪一部分进行进一步查找。
        
**实现**


<![image.png](https://pic.leetcode-cn.com/7de6ef012f490979bd93ff358ea0170e060512c923e4a998971e16f58ca3573d-image.png),![image.png](https://pic.leetcode-cn.com/ac12c7c1582c3c528a4fd***1cca962a89d93b87ed594d73e944ce99329bb72a-image.png),![image.png](https://pic.leetcode-cn.com/00f29febc2d450068c0ba01fc5***11f6449c51385efc783453ab86b4b431bb5-image.png),![image.png](https://pic.leetcode-cn.com/377e27f31fc31fa2bb74aa60fc1140e261be36a9e43a29117c7fbaf138877c69-image.png),![image.png](https://pic.leetcode-cn.com/2986df24625ffba2483298cc9d43058f9e3306c786932f292a51caf2a91546a5-image.png),![image.png](https://pic.leetcode-cn.com/1989a5025216166fa2fbc3d9287fa6e92ced8a3b8a78824d3a2a9a38d5227d42-image.png),![image.png](https://pic.leetcode-cn.com/7322d0ee8e47dd43a864a0a08616dc95949cc02a8024e4cff223e915e2dd8098-image.png)>

```Java [solution1]
class Solution {
  public boolean searchMatrix(int[][] matrix, int target) {
    int m = matrix.length;
    if (m == 0) return false;
    int n = matrix[0].length;

    // 二分查找
    int left = 0, right = m * n - 1;
    int pivotIdx, pivotElement;
    while (left <= right) {
      pivotIdx = (left + right) / 2;
      pivotElement = matrix[pivotIdx / n][pivotIdx % n];
      if (target == pivotElement) return true;
      else {
        if (target < pivotElement) right = pivotIdx - 1;
        else left = pivotIdx + 1;
      }
    }
    return false;
  }
}
```

```Python [solution1]
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m = len(matrix)
        if m == 0:
            return False
        n = len(matrix[0])
        
        #二分查找
        left, right = 0, m * n - 1
        while left <= right:
                pivot_idx = (left + right) // 2
                pivot_element = matrix[pivot_idx // n][pivot_idx % n]
                if target == pivot_element:
                    return True
                else:
                    if target < pivot_element:
                        right = pivot_idx - 1
                    else:
                        left = pivot_idx + 1
        return False
```

```C++ [solution1]
class Solution {
  public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) return false;
    int n = matrix[0].size();

    // 二分查找
    int left = 0, right = m * n - 1;
    int pivotIdx, pivotElement;
    while (left <= right) {
      pivotIdx = (left + right) / 2;
      pivotElement = matrix[pivotIdx / n][pivotIdx % n];
      if (target == pivotElement) return true;
      else {
        if (target < pivotElement) right = pivotIdx - 1;
        else left = pivotIdx + 1;
      }
    }
    return false;
  }
};
```

**复杂度分析**

* 时间复杂度 : 由于是标准的二分查找，时间复杂度为$O(\log(m n))$。
* 空间复杂度 : $O(1)$。