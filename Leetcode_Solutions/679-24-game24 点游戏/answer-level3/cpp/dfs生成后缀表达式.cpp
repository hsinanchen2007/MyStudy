### 解题思路
深度搜索生成后缀表达式
sign数组表示a数组中相应位置是数字还是运算符，0数字 1`+` 2`-` 3`*` 4`/`
每一层dfs给后缀表达式添加一个数字或者符号(当数字的个数多余符号的个数+1则可以添加符号)
当数字与符号的个数为4与3时，计算后缀表达式的结果

### 代码

```cpp
class Solution {
public:
    int flag;
    int numap[4] = {0, 0, 0, 0};

    //sign表示a中相应位置是数字还是运算符，0数字 1+ 2- 3* 4/
    bool cal(vector<double> &a, vector<int> &sign)  //计算后缀表达式的结果
    {
        double res = 0;
        stack<double> s;
        for (int i = 0; i < a.size(); i++)
        {
            if (sign[i] == 0)
            {
                s.push(a[i]);
            }
            else
            {
                double x = s.top();
                s.pop();
                double y = s.top();
                s.pop();
                switch (sign[i])
                {
                    case 1:s.push(x + y); break;
                    case 2:s.push(x - y); break;
                    case 3:s.push(x * y); break;
                    case 4:
                        if (abs(y) < 1e-6)
                        {
                            cout << "x div 0" << endl;
                            return 0;
                        }
                        s.push(x / y); break;
                }
            }
        }
        if (s.size() == 1&& abs(s.top() - 24) < 1e-6)
        {
            
            flag = 1;
            return 1;
        }
        return 0;
    }

    void dfs(vector<int> &nums, int nnum, int nsign, vector<double> &a, vector<int> &sign)
    {
        if (nnum == 4&& nsign == 3)
        {
            cal(a, sign);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (flag)
            {
                return;
            }
            if (numap[i] == 1)
            {
                continue;
            }
            numap[i] = 1;
            a.push_back(nums[i]);
            sign.push_back(0);

            dfs(nums, nnum + 1, nsign, a, sign);

            sign.pop_back();
            a.pop_back();
            numap[i] = 0;
        }
        if (nnum > nsign + 1)   //数字多，可以加符号
        {
            a.push_back(0);
            for (int j = 1; j < 5; j++)
            {
                if (flag)
                {
                    return;
                }
                sign.push_back(j);
                dfs(nums, nnum, nsign + 1, a, sign);
                sign.pop_back();
            }
            a.pop_back();
        }
    }

    bool judgePoint24(vector<int>& nums) {
        flag = 0;
        vector<double> a;
        vector<int> sign;
        dfs(nums, 0, 0, a, sign);
        return flag == 1;
    }
};
```