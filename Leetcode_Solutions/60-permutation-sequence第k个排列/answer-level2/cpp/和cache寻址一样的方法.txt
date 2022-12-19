### 解题思路
这个和cache寻址一样的方法，选group，然后选line，最后选word
给一个绝对数值，然后多级查找，第一级是(n-1)!为一组，第二级是(n-2)!个数字为一组，一组表示最高位的数字一样

### 代码

```cpp
class Solution {
public:
    string getPermutation(int n, int k) {
        string s, res;
        for(int i = 1; i <= n; ++i){
            s += to_string(i);
        }
        int len = n;
        --n; --k;
        long n_factorial = getFactorial(n);
        while(s.size() > 1){
            int idx = k / n_factorial;
            res += s[idx];
            removeString(s, idx);
            // for next loop
            k = k % n_factorial;
            n_factorial /= n; --n; 
        }
        res += s[0];
        return res;
    }

    long getFactorial(int n){
        long res = 1;
        while(n){
            res *= n; --n;
        }
        return res;
    }

    void removeString(string &str, int idx){
        if(idx == str.size() - 1){
            str = str.substr(0, idx);
        }else{
            str = str.substr(0, idx) + str.substr(idx+1, str.size() - idx - 1);
        }
    }
};
```

###结果
执行用时 : 4 ms , 在所有 C++ 提交中击败了 74.66% 的用户 
内存消耗 : 6.1 MB , 在所有 C++ 提交中击败了 100.00% 的用户