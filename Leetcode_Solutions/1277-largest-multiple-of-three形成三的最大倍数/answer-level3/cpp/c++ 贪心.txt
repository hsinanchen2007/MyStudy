先降序排列，把问题转化为：**怎么删除数能整除 3 并且最大。**

记 t 为 digits 的数字和，然后可以分为3种情况：t 余数为0，直接返回。 t 余数为1， t 余数为2。

对于 t 余数为 r=1,2 两种情况中，我们可以直接查询 cnt 是否存在除以 3 得相同余数 r 的数，因为显然，**只删掉一个数结果肯定是最大的**。我们从后往前扫数组删除即可。

如果余数 r == 1 但 cnt[r] == 0，那么我们可以查看 cnt[2] 是否有 2 个，因为**删掉两个余数为 2 的数等价于删除 1 个余数为 1 的数**，比如 [9,8,6,8,6], t = 37, r = 1, 删除两个 8 即可。

如果余数 r == 2，同理，相应操作即可。

```c++
class Solution {
private:
    int cnt[3];  //  统计余数出现了多少次
    
public:
    string largestMultipleOfThree(vector<int>& digits) {
        int n = digits.size();
        int t = 0;
        string res;
        sort(digits.begin(), digits.end(), greater<int>());
        for (auto i : digits)
        {
            res += to_string(i);
            t += i;     // t 为digits中的数字和
            cnt[i % 3] ++;
        }
        if (!t) return "0";
        if (t < 3) return "";
        if (t % 3 == 0) return res;

        int r = t % 3;       // r 为 digits 和除以 3 的余数
        if (cnt[r])     // digits 数字中存在余数 r，直接从后往前扫一遍找到它
        {       
            for (int i = n - 1; i >= 0; i --)
                if (digits[i] % 3 == r) return res.substr(0, i) + res.substr(i + 1);            
        }

        else if (r == 2 && cnt[1] > 1)
        {
// digits 不存在和 r 余数相同的数字，那么查看是否有 >=2 个以上 r - 1 或 r + 1，如果都没有则不可整除3，返回 ""
            int cur = 0;
            int l1, l2;
            for (int i = n - 1;  i >= 0; i --)
            {
                if (digits[i] % 3 == 1) 
                {
                    cur ++;
                    if (cur == 1) l1 = i;
                    else l2 = i;
                }
                if (cur == 2) break;
            }
            res.erase(res.begin() + l1, res.begin() + l1 + 1);
            res.erase(res.begin() + l2, res.begin() + l2 + 1);
        }

        else if (r == 1 && cnt[2] > 1)
        {
            int cur = 0;
            int l1, l2;
            for (int i = n - 1;  i >= 0; i --)
            {
                if (digits[i] % 3 == 2) 
                {
                    cur ++;
                    if (cur == 1) l1 = i;
                    else l2 = i;
                }
                if (cur == 2) break;
            }
            res.erase(res.begin() + l1, res.begin() + l1 + 1);
            res.erase(res.begin() + l2, res.begin() + l2 + 1);
        }
        else return "";
        return res;
    }
};
```