### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:

    static int weight(int num)
    {
        int count = 0;

        while (num != 1)
        {
            if (num % 2 != 0)
            {
                num = 3 * num + 1;
            }
            else
            {
                num /= 2;
            }

            ++count;
        }

        return count;
    }

    static bool cmp(int l, int r)
    {
        int wl = weight(l);
        int wr = weight(r);

        if (wl < wr)
        {
            return true;
        }
        else if (wl == wr)
        {
            return l < r;
        }

        return false;
    }

    int getKth(int lo, int hi, int k) {

        vector<int> v(hi - lo + 1);

        for (int i = lo; i <= hi; ++i)
        {
            v.at(i - lo) = i;
        }

        sort(v.begin(), v.end(), cmp);

        return v.at(k - 1);
    }
};

```