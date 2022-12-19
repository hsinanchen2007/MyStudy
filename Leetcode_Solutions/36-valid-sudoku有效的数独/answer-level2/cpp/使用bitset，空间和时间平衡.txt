√ Accepted
  
√ 504/504 cases passed (4 ms)
  
√ Your runtime beats 100 % of cpp submissions
  
√ Your memory usage beats 87.54 % of cpp submissions (9.5 MB)

我觉得如果还有什么可以改进的就是box的vector可以设置为3个，每三行重置一下，可以更省空间
![微信截图_20190525041834.png](https://pic.leetcode-cn.com/a0f9053344252738ffb82f9c0da81fd5c3bbf8d61520ff5b77cfae900aea0689-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20190525041834.png)
```
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        char k;
        int num;
        bitset<9> hang;
        vector<bitset<9>> lie(9, hang), box(9, hang);
        for (int i = 0; i < 9; ++i) //行
        {
            for (int j = 0; j < 9; ++j) //列
            {
                k = board[i][j];
                if (k != '.')
                {
                    num = k - '0' - 1;
                    if (hang[num] == 0 && lie[j][num] == 0 && box[i / 3 * 3 + j / 3][num] == 0)
                        hang[num] = lie[j][num] = box[i / 3 * 3 + j / 3][num] = 1;
                    else
                        return 0;
                }
            }
            hang.reset();
        }
        return 1;
    }
};
```