### 解题思路
这题跟以往的二维数组给定的参数不一样。让人摸不着头脑
+ `ASize`:二维数组行数。
+ `*AColSize`:二维数组列数！不知道搞个指针干哈？可能不一样列数，好像测试没遇到过。
+ `*returnSize`:常规的返回二维数组行数是多少。
+ `**returnColumnSizes`:最奇怪，以往要申请数组，然后去赋值每行有多少列。但是现在题目既然给了`*AColSize`,所以直接赋值即可。

也许因该测试用例跑的都是等列的数组，所以下面代码使用`AColSize[0]`获得每列大小过了测试吧。最保险的方式就是使用每行每列这样一定不会出错的。

小细节：
1. 进行行反转时，只需要对位反转的相同才进行
    + 比如[1,0,1]->[1,0,1]->[0,1,0].但是[0,0,1]->[1,0,0]->[0,1,1]\(两端一样\)，所以少做一步，就多一步判断
2. 奇偶数考虑：与只反转不一样，因为题目最后还要对01倒置，所以当奇数时，处于对称轴上的数要颠倒。
    + 因此使用for循环到一半的时候，要考虑奇偶性。而向上取整`(col + 1) / 2`解决奇偶问题。
    + 其实双指针把条件换成`left<=right`即可解决这个问题。

### for循环颠倒向上取整

```c []
int** flipAndInvertImage(int** A, int ASize, int* AColSize, int* returnSize, int** returnColumnSizes){
    *returnSize = ASize;
    returnColumnSizes[0] = AColSize;  // 直接赋值
    for (int row = 0; row < ASize; row++) {
        for (int col = 0; col < (AColSize[row] + 1) / 2; col++) {  // 反转一半
            // 只有相同的才反转，因为不同刚好位置颠倒,因此相同的就是一样结果
            if (A[row][col] == A[row][AColSize[row] - 1 - col]) {
                A[row][col] = A[row][AColSize[row] - 1 - col] = 1 - A[row][col];  // 相反操作
            }
        }
    }
    return A;
}
```

### 双指针颠倒
```c []
int** flipAndInvertImage(int** A, int ASize, int* AColSize, int* returnSize, int** returnColumnSizes){
    *returnSize = ASize;
    returnColumnSizes[0] = AColSize;
    int left, right;
    for (int row = 0; row < ASize; row++) {
        // 双指针循环条件：两指针可等
        left = 0; right = AColSize[row] - 1;
        while (left <= right) {
            // 只有相同的才反转，因为不同刚好位置颠倒,因此相同的就是一样结果
            if (A[row][left] == A[row][right]) {
                A[row][left] = A[row][right] = 1 ^ A[row][right];  // 异或操作
            }
            left++; right--;
        }
    }
    return A;
}
```
```python3 []
class Solution:
    def flipAndInvertImage(self, A: List[List[int]]) -> List[List[int]]:
        return [[A[row][col] ^ 1 for col in range(len(A[0]) - 1, -1, -1)] for row in range(len(A))]
```