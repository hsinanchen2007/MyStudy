### 解题思路
贼蛋疼的题目，自己用笔写一下从一个(a, b)变换到其他点的思路，从最外层开始旋转。
如果连交换用到的临时变量都不用，那就用异或来做两个数交换。

建立坐标系，从左到右为x，从上到下为y。矩阵中，我们的原点是在左上角的，我们需要先把它移动到矩阵的中间，这个很简单，但是注意边长是矩阵的长度减1！
然后你就会发现，假设左上角的某个点(a, b), 它右边的点是(-b+n, a), 下面的点是(b, -a+n), 右下方的点是(-a+n, -b+n). 注意一下，这里的括号第一个数是代表x轴的数，第二个数是y轴的数，在我们的代码中，方括号一个是y坐标，第二个是x坐标。所以需要调换一下位置。


### 代码

```cpp
class Solution {
public:
    void swipInt(int &a, int &b) {
        a = a ^ b;
        b = a ^b;
        a = a ^ b;
    }
    void rotate(vector<vector<int>>& matrix) {
        long n = matrix.size() - 1;
        if (n < 1) {
            return;
        }
        for (int b=0; b<n; b++) {
            for (int a=b; a<n-b; a++) { //这里注意一下开始和结束都应该缩小。
                swipInt(matrix[b][a], matrix[a][-b+n]); //先和右边的点互换
                swipInt(matrix[b][a], matrix[-a+n][b]); //再和下边的点互换
                swipInt(matrix[-a+n][b], matrix[-b+n][-a+n]); //下边和右下角的点再互换
            }
        }
    }
};
```