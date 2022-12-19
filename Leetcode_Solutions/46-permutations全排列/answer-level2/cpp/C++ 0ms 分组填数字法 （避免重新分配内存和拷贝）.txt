（以下讨论基于C++）

### 问题：

1. 官方题解中的回溯法（和其他类似的解法）在不断地往res（即vector<vector<int>>，vov）中 push_back(nums)，这个操作实际上会触发res这个vov多次重新分配内存和子vector拷贝
2. 其他类似插入法的方法，也会导致子vector多次重新申请内存，并且对vector来说，insert方法的时间复杂度是O(n)

### 目标：

避免vector的重新分配内存，避免insert方法导致的多余拷贝

#### 思路:
~~一个可能的解决方法是改用list，但是题目要求的是vector，加上list占用内存比vector多，所以不考虑list~~

1. 构造res
已知nums包含n个独特元素，返回结果res的结构是可以确定的，即一个size为n!的vector，其中每个元素是size为n的vector（大小为n! x n的矩阵）。
所以一开始就可以把res构造出来，`vector<vector<int>> res(n!, vector<int>(n, 0))`（其中每个数字初始化为零）。
剩下的只需要往res里面填数字。

2. 填数字
~~（暂时想不出元素(i, j)的公式，采用比较笨的分组填数字方法）~~
以`nums = {1, 2, 3, 4}`为例，res为一个size为24的vector<vector<int>>，我们需要把res填成下面这个样子：
```
1 2 3 4 
1 2 4 3 
1 3 4 2 
1 3 2 4 
1 4 2 3 
1 4 3 2 
2 3 4 1 
2 3 1 4 
2 4 1 3 
2 4 3 1 
2 1 3 4 
2 1 4 3 
3 4 1 2 
3 4 2 1 
3 1 2 4 
3 1 4 2 
3 2 4 1 
3 2 1 4 
4 1 2 3 
4 1 3 2 
4 2 3 1 
4 2 1 3 
4 3 1 2 
4 3 2 1 
```

通过观察可以发现，res可以被分为4组，分别是以1开头的6个vector，以2开头的6个vector...以此类推
其中以1开头的6个vector又可以被分为3组，分别是以12开头的2个vector，以13开头2个vector...以此类推
其中以12开头的2个vector又可以被分为2组，分别是以123开头的1个vector，以124开头的1个vector
其中以123开头的1个vector又可以被分为1组，是排列为1234的1个vector
...以此类推

规律是，**每组可以根据剩下的n个选项分为n组，每组的所有vector以同一个选项打头**

#### talk is cheap:

``` c++
class Solution
{
public:
    using vec_iter = vector<vector<int>>::iterator;

    int get_factorial(int num)
    {
        int fac = 1;
        for (int i = 1; i <= num; ++i)
        {
            fac *= i;
        }

        return fac;
    }

    void _fill_leader_recursively(vec_iter group_iter, size_t group_size,
                                  list<int> &candidates, int leader = -1, bool entry = true)
    {
        // fill leader
        if (!entry)
        {
            for (int i = 0; i < group_size; ++i)
            {
                *((*(group_iter + i)).rbegin() + candidates.size()) = leader;
            }
        }

        // divide into groups
        if (!candidates.empty())
        {
            int sub_group_size = group_size / candidates.size();
            for (int i = 0; i < group_size; i += sub_group_size)
            {
                int sub_leader = *candidates.begin();
                candidates.pop_front();
                _fill_leader_recursively(group_iter + i, sub_group_size, candidates, sub_leader, false);
                candidates.push_back(sub_leader);
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        int res_size = get_factorial(nums.size());
        vector<vector<int>> results(res_size, vector<int>(nums.size(), 0));
        list<int> nums_list(nums.begin(), nums.end());
        _fill_leader_recursively(results.begin(), results.size(), nums_list);

        return results;
    }
};
```