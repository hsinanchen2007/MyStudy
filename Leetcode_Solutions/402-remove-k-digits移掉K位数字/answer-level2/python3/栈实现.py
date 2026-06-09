思路
1. 问题拆分，考虑最简单的情况，12354200移掉一位数字，什么情况会最小。
2. 只有前一位数字比后面一位大时，去掉该位，才能使数字变小。5>4. 且越高位改变，值变得越小。
3. 移动k位，就是上述过程重复k次，且因为每次从最左边开始找逆序，因此可以用栈一轮完成。

特殊情况
1. 前导0, 00321，移掉一位数字后是0021，前导0要去掉。可以取值时为空不取0，或者最后再去掉前导0
2. 所有数字有序，移动位数不足。 如 12345移动3位，最后移动一轮，直至k为0.

```Python [] 
 class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        if k == 0 or not num:
            return num
        if k >= len(num):
            return "0"
        
        res = []
        for ch in num:
            while k > 0 and res and res[-1] > ch:
                k -= 1
                res.pop()
            if res or not res and ch != '0':
                res.append(ch)
        
        while res and k > 0:
            res.pop()
            k -= 1
        
        return '0' if not res else "".join(res)
```

```C++ [] 
class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() == 0 || k == 0)
            return num;
        if (k >= num.size())
            return "0";
        
        string res;
        for (auto ch: num) {
            while (k > 0 && !res.empty() && res.back() > ch) {
                res.pop_back();
                k--;
            }
                
            if (!res.empty() || res.empty() && ch != '0') // 前导0不要
                res.push_back(ch);
        }
        while (k > 0 && !res.empty()) { // 去除的位数不足k个，继续去除
            k--;
            res.pop_back();
        }
        return res.empty()? "0": res;
    }
};
```

