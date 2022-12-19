自己想了很久，就是如何检测下一个要放的皇后是否会与前面放的皇后冲突，感觉检测起来非常麻烦，是我的思路有问题，看了外国人的这个解法，就是使用3个数组存储皇后的两个斜线位置和列位置，非常聪明的方法。

更新了自己琢磨的递推解法，未剪枝，理论上第一行只要看一半就行，有大神知道的话评论一下感激不尽，第二种解法速度更快，但肯定不完美。

![微信截图_20190524005900.png](https://pic.leetcode-cn.com/d030bd7157de4f9d08ea347ba0fe56889553e7645c496d18f495062a52ac453d-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20190524005900.png)

1. 递归法
```
class Solution
{
private:
    void search(int n, int r, vector<string> &v, vector<vector<string>> &vv, vector<int> &forward,
 vector<int> &backward, vector<int> &columns)
    {
        if (r == n)
            vv.push_back(v);
        for (int c = 0; c < n; c++)
        {
            if (!forward[c + r] && !backward[r + n - c - 1] && !columns[c])
            {
                v[r][c] = 'Q';
                forward[c + r] = backward[r + n - c - 1] = columns[c] = 1;
                search(n, r + 1, v, vv, forward, backward, columns);
                forward[c + r] = backward[r + n - c - 1] = columns[c] = 0;
                v[r][c] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<int> forward(2 * n), backward(2 * n), columns(n);//初始化三个数组，保存是否被占用的标志，
        //极端值下标为2*n-1要可访问，就得开2*n大小的数组，最后一个列数，就最大下标也就是n-1，开n的就行了
        vector<vector<string>> vv;
        vector<string> v(n, string(n, '.'));
        search(n, 0, v, vv, forward, backward, columns);
        return vv;
    }
};
```

2. 递推法
```
class Solution
{
public:
    typedef vector<string> vs;
    typedef vector<int> vi;
    typedef vector<vector<string>> vvs;
    //与上面方法一致，都是3个数组存放，可改进为使用string字符串存放是否访问过
    vector<vector<string>> solveNQueens(int n)
    {
        vvs result;
        vs v(n, string(n, '.'));
        vi f(n * 2), b(n * 2), c(n);
        stack<int> res;//用栈存放列的数据，行就是i栈的top就是列，控制进栈出栈
        for(int i = 0, j = 0; ;)
        {
            if (j == n)
            {
                if (i == 0)
                    break;
                j = res.top();
                --i;
                v[i][j] = '.';
                f[j + i] = b[i + n - j - 1] = c[j] = 0;
                ++j;
                res.pop();
                continue;
            }
            if (!f[j + i] && !b[i + n - j - 1] && !c[j])
            {
                res.push(j);
                v[i][j] = 'Q';
                f[j + i] = b[i + n - j - 1] = c[j] = 1;
                ++i;
                j = 0;
                if (i == n)
                    result.push_back(v);
                continue;
            }
            ++j;
        }
        return result;
    }
};

```





