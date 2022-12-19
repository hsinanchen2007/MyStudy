### 解题思路
首先明确一点：不管多长的多项式运算，最后一步一定是两个明确数值的运算。
    如 `8*（4-7）-6*2`  最后一步是 `（-24）-12`， 其中`-24`和`6`是明确的
再分解一下左边：上例中的得到 `-24` ，也是同样有最后一步是两个明确的数值运算
    `8 * （-3）`，同样的右边是  `6 * 2 `
再分解一下左边，容易得到结束点是：剩下一个数值或者两个（理论上也可以用 一个 统一解释）

完整的分解过程(宽度)：
    输入:`2*3-4*5`（已转换）
    第一步的分解：a:`2`和`3-4*5`；b:`2*3`和`4*5`；c:`2*3-4`和`5`；
    第二部的细分：a部分：左边：直接返回`2` 右边：在分解，aa:`3`和`4*5`，ab:`3-4`和`5`
    补充：同一个符号的左右各会产生至少一个，至多多个数值。左多个数和右多个数进行运算（两个循环搞定所有结果）   如a:`2`和`3-4*5` ，左边产生`2`，右边产生`-5`和`-17`，那么a这一级最终有`-10`，`-34`两个数值。

主要就是遍历符号，分成左右两部分不断分，最后在合。
因为每一层都有贮存开销，在空间复杂度还需要优化。（时间效果4ms）

### 代码

```cpp
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        int pre = 0;
        vector<int>arry;
        int k = 1;
        for (int i = 0; i < input.length(); i++)
            if (input[i] == '+' || input[i] == '-' || input[i] == '*'|| i == input.length()-1)
            {//将字符串转换成数学式子，考虑同一储存时符号字符与实际数值冲突的问题，
            //设置-1：+，-2：-，-3：*  没有使用c++提供的函数写这一步
                int s = 0;
                int j = i == (input.length() - 1) ? i: i - 1;
                for (; j >= pre; j--,k*=10)
                    s += (input[j] - '0') * k;
                arry.push_back(s);
                k = 1;
                pre = i + 1;
                if(input[i] == '+')
                    arry.push_back(-1);
                else if (input[i] == '-')
                    arry.push_back(-2);
                else if (input[i] == '*')
                    arry.push_back(-3);
            }
        return  detail(arry,0,arry.size()-1);
    }
    vector<int> detail(vector<int>& arry, int left, int righ)
    {
        vector<int>tmep;
        if (left == righ)
        {
            tmep.push_back(arry[left]);
            return tmep;
        }
        else if (righ - left == 2) {
            if (arry[left + 1] == -1)
                tmep.push_back(arry[left] + arry[righ]);
            else if (arry[left + 1] == -2)
                tmep.push_back(arry[left] - arry[righ]);
            else
                tmep.push_back(arry[left] * arry[righ]);
            return tmep;
        }

        vector<int>lef, rig;
        for(int j=left;j<=righ;j++)
            if (arry[j] < 0)
            {
                lef = detail(arry, left, j - 1);
                rig =detail(arry, j + 1, righ);  
                deal(tmep, lef, rig,arry[j]);
            }
        return tmep;
    }

    void deal(vector<int>& tmep, vector<int>& l, vector<int>& r,int sig)
    {//大致就是左边集合每个元素和右边集合每个元素进行（sin决定的符号）运算，没运算成一个，放入tmep
        for(int i=0;i<l.size();i++)
            for (int j = 0; j < r.size(); j++)
            {
                if (sig == -1)
                    tmep.push_back(l[i] + r[j]);             
                else if (sig == -2)
                    tmep.push_back(l[i] - r[j]);
                else
                    tmep.push_back(l[i] * r[j]);
            }
    }
};
```