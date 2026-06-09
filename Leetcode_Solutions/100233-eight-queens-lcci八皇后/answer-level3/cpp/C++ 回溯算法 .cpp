回溯的处理思想，有点类似枚举搜索。我们枚举所有的解，找到满足期望的解。为了有规律地枚举所有可能的解，避免遗漏和重复，我们把问题求解的过程分为多个阶段。每个阶段，我们都会面对一个岔路口，我们先随意选一条路走，当发现这条路走不通的时候（不符合期望的解），就回退到上一个岔路口，另选一种走法继续走。
```cpp
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        res.reserve(n);
        callbackqueen(0, n);
        return s;
    }
    void callbackqueen(int row, int n)
    {
        //n个棋子都放好了，我们就将这一次的结果保存起来,调用print函数
        if(row == n)
        {
            s.push_back(print(n));
            return;
        }
        //每一个棋子都有n个存放的方法，我们就对每个方法进行判断
        for(int i = 0; i < n; ++i)
        {
            //如果可以放，我们就将其结果存起来，然后到下一行
            if(Isok(row, i))
            {
                res[row] = i;
                callbackqueen(row+1, n);
            }
        }
    }
    bool Isok(int row, int column)
    {
        //我们只需对row行之前的行数进行判断,因为它前面的行数都放好

        int left = column -1; //左上角
        int right = column + 1; //右上角
        for(int i = row -1; i >= 0; --i)
        {
            //判断这一列是否有元素
            if(res[i] == column)
                return false;
            //判断左上角是否有元素
            if(left >= 0 && res[i] == left)
                return false;
            //判断右上角是否有元素
            if(res[i] == right)
                return false;
            --left, ++right;
        }
        return true;
    }

    vector<string> print(int n)
    {
        vector<string> vec;
        for(int i = 0; i < n; ++i)
        {
            string temp("");
            for(int j = 0; j < n; ++j)
            {
                if(res[i] == j)
                {
                    temp += "Q";
                }
                else
                {
                    temp += ".";
                }
            }
            vec.push_back(temp);
        }
        return vec;
    }

private:  
    vector<int> res;
    vector<vector<string>> s;
};

```