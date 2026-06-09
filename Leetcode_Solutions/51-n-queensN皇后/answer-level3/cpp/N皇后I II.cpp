
![image.png](https://pic.leetcode-cn.com/092451fd247d699637b6c93865285c1902a7c822d2f15e8e2bc3a9dc6d42f245-image.png)

# N皇后I  

主对角线和副对角线
用一维坐标来模拟每个皇后在二维坐标系中位置

```
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
            vector<vector<string>> res;
            string s(n, '.');
            vector<string> vec(n, s);
            if (n == 0 )
            {
                return res;
            }
            if(n == 1)
            {
                vec[0][0] = 'Q';
                res.push_back(vec);
                return res;
            }
            vector<int> Checkerboard(n, 0);


            for (int i = 0; i < n; i++)
            {
                Checkerboard[0] = i;  //在第 0 行的 第 i 列上放置第一个皇后  
                setQueenes(Checkerboard, 1, n,res,vec);
            }

            return res;
        }
       

        void setQueenes(vector<int>& Checkerboard,
            int cut,    //表示在 第 n行防止元素
            int n,
            vector<vector<string>>& res,
            vector<string> &vec
        )
        {
            if (cut == n)
            {
                for (int i = 0; i < n; i++)
                {
                    vec[i][Checkerboard[i]] = 'Q';
                }
                res.push_back(vec);
                for (int i = 0; i < n; i++)
                {
                    vec[i][Checkerboard[i]] = '.';
                }
                return;
            }
            for (int col = 0; col < n; col++)
            {
                bool isSetQueens = true;
                for (int row = 0; row < cut; row++)
                {
                    if (Checkerboard[row] == col    //判断列是否可以放置皇后
                        || row - Checkerboard[row] == cut - col  //主对角线是否可以防置皇后
                        || row + Checkerboard[row] == cut + col  //副对角线是否可以放置皇后
                        )
                    {
                        isSetQueens = false;
                        break;
                    }
                }

                if (isSetQueens)
                {
                    Checkerboard[cut] = col;
                    setQueenes(Checkerboard, cut + 1, n, res,vec);
                }
            }
        }
};

```

# N皇后II
```
class Solution {
public:
    int totalNQueens(int n)
        {
            if (n == 0 || n == 1)
                return n;

            vector<int> Checkerboard(n, 0);
            int res = 0;

            for (int i = 0; i < n; i++)
            {
                Checkerboard[0] = i;  //在第 0 行的 第 i 列上放置第一个皇后  
                setQueenes(Checkerboard, 1, n,res);
            }
            return res;
        }

        void setQueenes(vector<int>& Checkerboard,
            int cut,    //表示在 第 n行防止元素
            int n,
            int &res    
            )
        {
            if (cut == n)
            {
                res++;
                return;
            }
            for (int col = 0; col < n; col++)
            {
                bool isSetQueens = true;  
                for (int row = 0; row < cut; row++)
                {

                    /*
                        Checkerboard[row]  值代表  第row行的第Checkerboard[row]列存在一个皇后
                        row - Checkerboard[row]  这条主对角线已存在一个皇后
                        row + Checkerboard[row]  这条副对角线已存在一个皇后

                        此时判断 (cut ,col) 是否可以放置皇后
                        只需将下列的值与上面的值比较
                        cut当前行
                        col 列
                        cut - col主对角线
                        cut + col副对角线
                    */
                    
                    if (Checkerboard[row] == col    //判断列是否可以放置皇后
                        || row - Checkerboard[row] == cut - col  //主对角线是否可以防置皇后
                        || row + Checkerboard[row] == cut + col  //副对角线是否可以放置皇后
                        )
                    {
                        isSetQueens = false;
                        break;
                    }
                }

                if (isSetQueens)
                {
                    Checkerboard[cut] = col;
                    setQueenes(Checkerboard, cut + 1, n, res);
                }
            }
        }
};
```

