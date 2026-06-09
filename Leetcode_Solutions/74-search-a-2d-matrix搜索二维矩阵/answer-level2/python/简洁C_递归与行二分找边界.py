# ### 解题思路
# 有序：二分。要形成条件反射。但是本题是二维数组，且升序，最简单就是全部掏出来构建一维数组，完全升序，直接套二分查找模板即可。

# 1. base case:[]:返回假，或者列空为假。[[],[]]:假。`not matrix or not matrix[0]`条件`or`短路运算否则matrix存在一定存在列，但是列可能为空，返回假。
# 2. 二分查找`target`即可。

# ### 一、转换一维数组
# ```python3 []
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or not matrix[0]:
            return False
        left, right = 0, len(matrix) * len(matrix[0]) - 1
        array = [column for row in matrix for column in row]
        while left <= right:
            mid = ((right - left) >> 1) + left
            if array[mid] == target:
                return True
            elif array[mid] < target:
                left = mid + 1  # ascending
            else:
                right = mid - 1
        return False
# ```
# ### 二、二维数组正真作为一维看待(取余运算)
# 因为一直是升序，因此可以通过直接认为一维数组连续升序，则需要进行行列判断才行
# + 行的索引:`row = mid / *matrixColSize`
# + 列的索引:`column = mid % *matrixColSize`

# 这个效率最低。。。可能取余运算导致的。

# ```c []
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    if (!matrixSize || !matrixColSize) return false;  // 特判
    int left = 0, right = (*matrixColSize) * matrixSize - 1, mid;
    int row, column;  // 代表行列
    while (left <= right) {
        mid = left + ((right - left) >> 1);
        row = mid / *matrixColSize;  // 除法取整行(定位此行)
        column = mid % *matrixColSize;  // 取余得到列(定位此列)
        if (matrix[row][column] == target) return true;
        else if (matrix[row][column] > target) right = mid - 1;
        else left = mid + 1;
    }
    return false;
}
# ```

# ### 三、递归
# 此题C递归写法参考[1351.统计有序数组中的负数个数](https://leetcode-cn.com/problems/count-negative-numbers-in-a-sorted-matrix)。
# 1. 特例跟上面一样，行空或者列空返回假
# 2. 递归二分搜索符合条件的行，满足要求的行才进行二分查找target
# 3. 行边界处理问题：行超界就是行二分终止

# ```c []
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    bool solve(int low, int high) {
        if (low > high) return false;  // 1.行二分结束
        int isrow = 0, isfind = false;  // 行找对了吗？isfind是否找到target
        int right = (*matrixColSize) - 1, left = 0, mid;
        int mid_row = (high - low) / 2 + low;  // 中间行 
        if (matrix[mid_row][0] > target) isrow = -1;  // 上找
        if (matrix[mid_row][right] < target) isrow = 1;  // 下找
        // 2.开始二分搜索
        if (isrow == 0) {  // 行对了才找，否则不找
            while (left <= right) {
                mid = (right - left) / 2 + left;  // 列中心
                if (matrix[mid_row][mid] == target) return true;
                else if (matrix[mid_row][mid] < target) left = mid + 1;
                else right = mid - 1;  // 左移高指针
            }
        }
        // 3.二分搜索可能存在行
        if (isrow > 0) return solve(mid_row + 1, high);  // 下找
        else if (isrow < 0) return solve(low, mid_row - 1);  // 上找
        return isfind;  // 4.行对了，返回是否找到
    }
    return matrixSize && (*matrixColSize) ? solve(0, matrixSize - 1) : 0;  // [[]],1
}
# ```

# ### 四、迭代二分正确姿势
# + 明确行二分是找范围，而不是找定值，比如[[1,2,3],[5,6,7]]找4，那么如果在0行找，首先判断末尾元素与起始元素与target大小而跳过查找。
# + 列二分是在**行确定**情况下才进行查找，不是暴力遍历行一个个查列元素。

# 也就是先对行的两端大小进行判断，与常规二分不同。
# ```
if (matrix[mid_row][0] > target) {
    right = mid_row - 1;  // 向上找
    refresh = true;  // 刷新
}
if (matrix[mid_row][(*matrixColSize)-1] < target) {
    left = mid_row + 1;  // 向下
    refresh = true;  // 刷新
}
# ```
# 上面两个if判断左右两个边界，`if-else if`会漏判`[[1],[1]]`这种情况。也是更新行查找的关键，如果`refresh=false`就证明找到正确的行，进行列二分查找即可。

# ```c []
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    if (!matrixSize || !(*matrixColSize)) return false;  // 特判
    int left = 0, right = matrixSize - 1, mid_row;  // 行二分查找
    bool refresh = false;  // 初始化为行二分是否刷新mid_row
    while (left <= right) {
        mid_row = left + ((right - left) >> 1);
        if (matrix[mid_row][0] > target) {
            right = mid_row - 1;  // 向上找
            refresh = true;  // 刷新
        }
        if (matrix[mid_row][(*matrixColSize)-1] < target) {
            left = mid_row + 1;  // 向下
            refresh = true;  // 刷新
        }
        if (!refresh) {  // 1.没刷新证明找到特定行
            int L = 0, R = (*matrixColSize) - 1, mid;  // 列二分操作
            while (L <= R) {
                mid = L + ((R - L) >> 1);
                if (matrix[mid_row][mid] == target) return true;
                else if (matrix[mid_row][mid] > target) R = mid - 1;
                else L = mid + 1;
            }
            break;  // 只要进来了，不满足就一定没找到
            // return false;
        }else refresh = false;  // 否则刷新为false
    }
    return false;  // 二分行找不到错误，返回假
}
# ```
# ### 5."乌龟"爬对角线O(m+n)
# 额，应该算是二维数组双指针吧，🥁
# 首先数组展开是升序的，那么可以通过每行边界值来确定范围，相当于长度一定的二分法！

# 为什么可以这样爬，为什么选择从对角线爬？
# + 因为数组的列大小是**←**且行元素是**↓**，即从对角线爬最快。
# + 当`matrix[row][column]>target`:
#     + 1.爬到下行了，想要通过`column--`搜索当前行内列是否有满足。
#     + 2.刚好是这行，依然通过`column--`搜索当前行内列是否有满足。
#     + 最终，找到就返回。否则`column < 0`超界不存在
# + 当`matrix[row][column]<target`:
#     + 1.此行不够？为什么不可以通过`column++`右移变大？不会的，因为之前从右侧过来的。
#     + 2.只能往下继续走即`row++`，直到找到或者超界。

# ```c []
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    if (!matrixSize || !(*matrixColSize)) return false;  // 特判
    int row = 0, column = (*matrixColSize) - 1, mid_row;  // 行二分查找
    while (row < matrixSize && column >= 0) {
        if (matrix[row][column] == target) return true;
        else if (matrix[row][column] > target) column--;
        else row++;
    }
    return false;
}
# ```

# 下面看一个动图，展示为什么可以爬，实际就是找分界线。
# ![乌龟爬展开.gif](https://pic.leetcode-cn.com/9b941c77a43368ca9ac5f6d799ee9f6a7d4a42093330e1845a4eae906e4755d8-%E4%B9%8C%E9%BE%9F%E7%88%AC%E5%B1%95%E5%BC%80.gif)

# 因为数组升序，爬的过程就是每次分段走，这段走的宽度就是列宽度。所以先确定查找数据的行数，然后再移动列去看是否找到，直到列超界，也就是跑到上一行的元素去就证明没找到。同样一直往下爬，使得行超界，一整条连起来的升序链最大值都小于target就是找不到。

# #### 5.1 "乌龟爬"与二分对比
# 比如在升序二维数组中找到`83`
# ![image.png](https://pic.leetcode-cn.com/5ac484cf750f373ab6cbc41ba7f829d2538a9105e7bc698fbf6ee1d92683b50f-image.png)
# 一共需要移动10步才找到结果。而二分查找就看图就行了。
# ![二分查找示意图.gif](https://pic.leetcode-cn.com/cfcfb9850be24fa6bbe4da5fc04ac7b0ed8e737659591c03e439a7e7334c5bbb-%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE%E7%A4%BA%E6%84%8F%E5%9B%BE.gif)

# 这种看起来比二分来的慢，因为从头一个个走，跟跳着走就差多了，尤其是搜索在最后位置。这种方法就是基于确定小范围，然后查找，类似的题目可以解决的就是：
# + [1351.统计有序数组中的负数个数](https://leetcode-cn.com/problems/count-negative-numbers-in-a-sorted-matrix)
# + [240.搜索二维矩阵Ⅱ](https://leetcode-cn.com/problems/search-a-2d-matrix-ii/)


# ## 综上：
# 行的二分查找正确方式是两端范围，同时还根据二分行查找抛弃不满足的行。在找到行的前提下再查找是否列中包含target。