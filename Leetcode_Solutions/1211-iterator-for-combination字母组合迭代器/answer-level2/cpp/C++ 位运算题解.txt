### 解题思路
纯位运算即可
假设有`n`个字母，从中抽`k`个出来
接下来以`n=6, k=3`为例，解释位运算过程：

假设当前数为：`010011`对应`bef`
则下一个数为：`011100`对应`bcd`
令`comp`为当前数`010011`，则
1，`x = comp & (1 + comp);` 去除数字最后的连续1部分，此时`x = 010000`
2，`t = x & -x;` 获取`x`的最小的值为`1`的位，此时`t = 010000`
3，`x = (x & (~t)) | (t >> 1);` 将`x`中最后一个值为`1`的位向前移动一位，此时`x = 001000`
4，`y = comp & (~(1 + comp));` 获取数字最后的连续1部分，此时`y = 000011`
5，`t >>= 2; while (y > 0 && y < t) y <<= 1;` 将y移动到紧贴x后面，此时`y = 001100`
6，更新`comp = x | y`即可，此时`comp = 011100`

### 代码

```cpp
class CombinationIterator {
public:
    string s;
    int k;
    int n;
    int comp;
    bool has_next;
    CombinationIterator(string characters, int combinationLength) {
        s = characters;
        reverse(s.begin(), s.end());
        k = combinationLength;
        n = s.size();
        comp = ((1 << k) - 1) << (n - k);
        has_next = true;
    }

    string next() {
        string res;
        for (int i = n - 1; i >= 0; --i) {
            if (comp >> i & 1) {
                res += s[i];
            }
        }
        int a = comp + 1;
        int x = comp & a;
        if (x == 0) {
            has_next = false;
            return res;
        }
        int t = x & -x;
        x = (x & (~t)) | (t >> 1);
        t >>= 2;
        int y = comp & (~a);
        while (y > 0 && y < t) y <<= 1;
        comp = x | y;
        return res;
    }

    bool hasNext() {
        return has_next;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```

![image.png](https://pic.leetcode-cn.com/d2e751417eb4f38d4b1967beb5138dee3e443837a2951bf416722b3eada69621-image.png)
