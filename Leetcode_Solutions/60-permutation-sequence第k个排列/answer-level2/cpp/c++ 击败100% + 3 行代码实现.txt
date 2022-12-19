### 1.常规想法
从第一个排列开始，按顺序列举每一个排列，直到列举到第k个。
```c++
class Solution {
public:
    string getPermutation(int n, int k) {
        string s = string("123456789").substr(0,n);
        for(int j = 1; j < k; ++j) next_permutation(s.begin(), s.end()); //罪过 罪过, 谢罪！
        return s;
    }
};
```
[next_permutation()](http://www.cplusplus.com/reference/algorithm/next_permutation/)还可以传入第三个参数comparison functor.有下一个排列则返回true,如果已经是最大排列，则返回false,并排列成最小排列。此外还有[prev_permutation()](http://www.cplusplus.com/reference/algorithm/prev_permutation/).
### 2.直接找到第k个排列
考虑到我们的目标仅仅是找到第k个排列，有没有办法不用列举中间的排列，直接根据输入信息和排列规律直接找到第k个排列？  

**在n个数字的排列中，根据手动排列的习惯，先固定第一个位置的数字，还剩下最多(n-1)!种排列，再由放到第一个位置的数字原先的位置i(从左往右第i个)的不同，表示跳过了i*(n-1)种排列。要找到第k个排列，先由i = k/(n-1)得出应该移到第一个位置的数字索引，并由k = k%(n - 1)更新k.** 

这样，我们可以从左往右遍历原先字符串的最小排列，每一次找到应该放在左边第一个位置的数字，将其添加到结果字符串中，并从原字符串中删除，然后对剩下的字符串重复这一操作，直到k==0。此外由于字符串最初的状态就是第１个排列，所以要将输入的k先减一。
```c++
class Solution {
    static const vector<int> fac;
public:
    string getPermutation(int n, int k) {
        string res;
        string s = string("123456789").substr(0, n);
        --k;
        while(k > 0)
        {
            size_t i = k/fac[n - 1];
            res.push_back(s[i]);
            s.erase(s.begin() + i);
            k %= fac[n - 1];
            --n;
        }
        return res + s;
    }
};
const vector<int> Solution::fac = {0,1,2,6,24,120,720,5040,40320,362880,3628800};
```
