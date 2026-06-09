### 解题思路
参考清华邓俊辉老师编著的《数据结构C++语言版》第三版，用迭代实现，手动维护用vector模拟的栈

### 代码

```cpp

class queen {
public:
    queen(int xx,int yy) :x(xx),y(yy)
    {

    }
    bool operator==(queen const& q)const {
        return ((x == q.x) ||
            (y == q.y) ||
            (x + y == q.x + q.y) ||
            (x - y == q.x - q.y));
    }
    bool operator!=(queen const& q)const {
        return !(*this == q);
    }

public:
    int x;
    int y;
};


class Solution {
public:
    bool find(const queen& q, vector<queen>& v)
    {
        if (v.empty())//首次没有比对，则直接返回可行
        {
            return true;
        }
        for (int i = 0; i < v.size(); i++)
        {
            if (q == v[i])
            {
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> rs;
        vector<string> map(n, string(n, '.'));//全部用'.'初始化
        string s;
        vector<queen> tmp_v;//模拟栈，栈记录的是返回位置，需要先跳到该位置，然后进行处理，比如将该地址弹出栈
        queen qq(0, 0);


        do
        {
            if (qq.x >= n || tmp_v.size() >= n)//判断是否要回溯到上一行，模拟递归函数返回（回溯条件由具体问题决定，本次为走到棋盘最左和最下）
            {
                qq = tmp_v.back();//回到返回位置
                map[qq.y][qq.x] = '.';//进行相应处理，因为此位置已经遍历完成，则置为初始值
                qq.x++;//寻找其他分支
                tmp_v.pop_back();//弹出该位置，因为它已经不是返回地址，返回地址为弹出后的栈顶值
            }
            else//否则继续遍历这一行
            {
                while (qq.x < n && (!find(qq, tmp_v)))//遍历这一行，和每个已找到的q直到找到空位或者遍历结束
                {
                    qq.x++;
                }
                if (qq.x < n)//如果是有空位
                {
                    tmp_v.push_back(qq);//放入记录数组，即人工栈
                    map[qq.y][qq.x] = 'Q';//按照题目要求标记
                    if (tmp_v.size() >= n)//若找到n个位置，则记录这个解
                    {
                        rs.push_back(map);
                    }
                    qq.y++; qq.x = 0;//进入下一行，是否超出棋盘边界，由下一次遍历判断
                }
            }
            //注意遍历完成的条件！！
        } while (!tmp_v.empty() || qq.x < n);
        return rs;   
    }
};
```