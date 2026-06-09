写的拼音，不要介意，heng代表横下标就是第几行，zong代表纵下标就是第几列，画了图看了一下，就是外层右边一列，从0-倒数第二个，按照逆时针交换下来就好了，然后再交换内层，以此类推，就这样写了。。。写完觉得肯定标准答案不是这样，但是觉得应该也没有重复，就没有改。。
```
class Solution
{
public:
    void jiaohuan(vector<vector<int>> &a, const int heng, const int zong, const int n)
    {
        swap(a[heng][zong], a[n - zong][heng]);
        swap(a[n - zong][heng], a[n - heng][n - zong]);
        swap(a[n - heng][n - zong], a[zong][n - heng]);
        return;
    }

    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size() - 1, t = 0, l = n; //用l记录方块图像的最大下标
        while (n > 0)
        {
            for (int i = 0; i < n; ++i)
                jiaohuan(matrix, i + t, l - t, l);//i+t代表要交换的那个横下标，l-t代表要交换的纵下标
//循环用来交换一列到底部最后一个前面的元素，最后一个因为就等于第一个，第一次就交换了，t就是交换好的层数
            n -= 2; //外层交换完了就交换内层了，内层肯定比外层小2个格子，就减2
            ++t;
        }
        return;
    }
};
```