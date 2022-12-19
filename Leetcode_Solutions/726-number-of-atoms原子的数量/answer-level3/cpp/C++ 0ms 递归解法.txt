![image.png](https://pic.leetcode-cn.com/442ab76759d4070b6f15514e6d48945b7490e4613f10e6e71e27d467f846c781-image.png)




### 解题思路
注释写得比较清楚，拆分了每一个小步骤。

分析：
1. 这里涉及到多个括号的嵌套，使用递归是最直接的想法。
2. 把基本框架定下来，问题的关键在于处理括号的情况，如何把次数累积传递，就增加了一个times来传参
3. 注意idx的调整。在求取name、times等的过程中直接对idx操作即可，没必要再重新处理，且要保持代码一致性，都在小功能函数内部做好对应过程



### 代码

```cpp
class Solution {
private:
void add_atom(map<string,int> & atoms, const string & formula, int times)
{
    size_t len = formula.size();
    if(len == 0) return;
    size_t idx = 0;
    string name;
    int num;
    while(idx < len)
    {
        //碰到括号
        if(formula[idx] == '(')
        {
            ++idx;
            size_t start = idx;
            size_t pos_brc = get_rbrc(formula, idx);
            size_t end = idx - 1;
            ++idx;
            int new_times = get_times(formula, idx) * times;
            add_atom(atoms, formula.substr(start, end - start + 1), new_times);
        }
        //未碰到括号
        else
        {
            name = get_name(formula, idx);
            num = get_num(formula, idx);
            atoms[name] += num * times;
        }
    }
}
//将idx指向对应的右括号位置并返回
size_t get_rbrc(const string & formula, size_t & idx)
{
    int num_lbrc = 1;
    while(num_lbrc != 0)
    {
        if(formula[idx] == ')') 
            --num_lbrc;
        else if(formula[idx] == '(') 
            ++num_lbrc;
        ++idx;
    }
    --idx;
    return idx;
}            
//获取times返回，并将idx指向数字后  
int get_times(const string & formula, size_t & idx)
{
    size_t start = idx, len = formula.size();
    while(idx < len && isdigit(formula[idx]))
        ++idx;
    return stoi(formula.substr(start, idx - start));
}
//获取一个名字，并调整idx到名字之后
string get_name(const string & formula, size_t & idx)
{
    size_t len = formula.size(), start = idx;
    idx++;
    while(idx < len && islower(formula[idx]))
        ++idx;
    return formula.substr(start, idx - start);
}
//获取一个数字，并调整idx在数字之后
int get_num(const string & formula, size_t & idx)
{
    size_t len = formula.size();
    int num = 0;
    while(idx < len && isdigit(formula[idx]))
    {
        num = num * 10 + (int)(formula[idx] - '0');
        ++idx;
    }
    if(num == 0)    return 1;
    return num;
}
//按要求返回string
string output(const map<string, int> & atoms)
{
    string explan;
    for(auto atom : atoms)
    {
        explan += atom.first;
        if(atom.second != 1)
            explan += to_string(atom.second);
    }
    return explan;
}

public:
    string countOfAtoms(string formula) {
        map<string, int> atoms;
        add_atom(atoms, formula, 1);
        return output(atoms);
    }
};
```




