1. 首先，显然将前半部分复制到后半部分，要比采取相反的措施，所得到差绝对值要小。

2. 然后，在复制前半部分后，考虑是否可以改变其中的某些数字，使差值更小。只考虑改变前半部分的数字（包括最中间的数字）。因为后半部分的数字会随着前半部分数字的改变而改变。

（1）如果将前半部分的数值 +1, 则最终的回文数一定比原数值要大。
（2）如果将前半部分的数值 -1, 则最终的回文数一定比原数值要小。
（3）如果将前半部分的数值 +N(N > 1), 则最终回文数与原数的差的绝对值值一定比（1）要大。
（4）如果将前半部分的数值 -N(N > 1), 则最终回文数与原数的差的绝对值值一定比（2）要大。

综上所述，“最近回文数”一定会在 前半部分数值 +1/不变/-1 中产生。如果自身是回文数，则只会在前半部分 +1/-1 中产生。

3. 如果有两个差值一样，则按照前半部分 -1, 不变, +1 的优先顺序来返回结果。从而得到最小的结果。

4. 特殊情况: 100...001, 100...000 应当返回 '99999'. 之前的算法由于前半部分的数字位数会减少一位, 所以会返回错误结果, 故应特殊对待.
比如：'100001' -> 前半部分减1 -> '99001' -> 前半复制到后半 -> '99099'(实际应为'99999').

代码如下：
```c++
class Solution {
public:
    string nearestPalindromic(string n) {
        // 去除前'0'
        removeLeadingZeros(n);

        // 特殊情况: 100...00, 100...001
        if(n.size() > 1 && n[0] == '1' && n[n.size() - 1] <= '1')
        {
            bool isSpecial = true;
            for(int x = 1; x < n.size() - 1; ++x)
            {
                if(n[x] != '0')
                {
                    isSpecial = false;
                    break;
                }
            }
            if(isSpecial)
            {
                n.erase(n.begin());
                for(int x = 0; x < n.size(); ++x)
                    n[x] = '9';
                return n;
            }
        }

        long long original = stoll(n);

        // 首先将前半部分复制到后半部分
        int i = 0, j = n.size() - 1;
        bool isAlreadyPalidrome = true;

        while(i < j)
        {
            if(n[j] != n[i])
            {
                n[j] = n[i];
                isAlreadyPalidrome = false;
            }
            ++i,--j;
        }

        long long diff0 = abs(stoll(n) - original);

        // 然后计算当前半部分 +1 后的数值, 并计算差值
        string nAdd = n;
        changeByFrontHalf(nAdd,1);
        long long diffAdd1 = abs(stoll(nAdd) - original);

        // 然后计算当前半部分 -1 后的差值, 并计算差值
        string nSub = n;
        changeByFrontHalf(nSub,-1);
        long long diffSub1 = abs(stoll(nSub) - original);

        // 如果本来就是回文数，则不包括其自身
        if(isAlreadyPalidrome)
        {
            if(diffSub1 <= diffAdd1)
                return nSub;
            else
                return nAdd;
        }
        else // 否则，找出最小，若相等，则优先级为 -1,0,+1.
        {
            if(diffSub1 <= diff0 && diffSub1 <= diffAdd1)
                return nSub;
            if(diff0 <= diffSub1 && diff0 <= diffAdd1)
                return n;
            else
                return nAdd;
        }
    }

    void removeLeadingZeros(string& n)
    {
        while(n.size() > 0 && n[0] == '0')
            n.erase(n.begin());
        
        if(n.size() == 0)
            n.push_back('0');
    }

    void changeByFrontHalf(string& n, int x)
    {
        if(x == -1)
        {
            for(int i = (n.size() - 1) / 2; i >= 0; --i)
            {
                if(n[i] != '0')
                {
                    n[i] -= 1;
                    removeLeadingZeros(n);
                    break;
                }
                else
                    n[i] = '9';
            }
        }
        else // x == 1
        {
            for(int i = (n.size() - 1) / 2; i >= 0; --i)
            {
                if(n[i] != '9')
                {
                    n[i] += 1;
                    break;
                }
                else
                    n[i] = '0';
            }

            if(n[0] == '0')
                n.insert(n.begin(), '1');
        }

        // 改变后半部分，得到回文数
        int i = 0, j = n.size() - 1;
        while(i < j)
        {
            n[j] = n[i];
            ++i,--j;
        }
    }
};
```






