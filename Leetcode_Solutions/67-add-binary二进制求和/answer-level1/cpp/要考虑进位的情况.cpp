### 解题思路
大众情况简单，对应各位相加就好
主要是边界条件"1" + "11" = "100"
要考虑两个string都遍历完了，但是carry还不为0的情况

### 代码

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() >= b.size()) return addHelp(a, b);
        else return addHelp(b, a);
    }

    string addHelp(string &a, string &b){
        int carry = 0;
        int i_a = a.size() - 1, i_b = b.size() - 1;
        while(carry > 0 || i_b >= 0){
            //cout << "i_a: " << i_a << " i_b: " << i_b << endl;
            int val_a = i_a >= 0? a[i_a] - '0': 0;
            int val_b = i_b >= 0? b[i_b] - '0': 0;
            int val = carry + val_a + val_b;
            carry = val / 2;
            val = val % 2;
            if(i_a >= 0) a[i_a] = val + '0';
            else a = to_string(val) + a; 
            //cout << "a: " << a << endl;
            --i_a; --i_b;
        }
        return a;
    }
};
```

###结果
执行用时 : 4 ms , 在所有 C++ 提交中击败了 85.94% 的用户 
内存消耗 : 6.6 MB , 在所有 C++ 提交中击败了 100.00% 的用户