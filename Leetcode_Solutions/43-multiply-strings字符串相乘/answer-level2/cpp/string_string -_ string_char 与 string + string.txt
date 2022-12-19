### 解题思路
这道题告诉我们一定要学会将一个复杂问题拆成多个简单的小问题去做
string* string -> string *char 与 string + string
string *char -> char * char
此外，需要注意边界条件num1 = "0" 与num2 = "0"

### 方法一(硬核的算)

```cpp
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.size() == 0 || num2.size() == 0) return "";
        string res = "0";
        for(int i = num2.size() - 1 ; i >= 0 ; --i){
            string partial_sum = stringMulChar(num1, num2[i], num2.size() - 1 - i);
            res = strAdd(res, partial_sum);
        }
        return res;
    }
    string stringMulChar(string &num1, char ch, int zero_num){
        int carry = 0, ch_num = ch - '0';
        string res;
        if(ch == '0' || num1 == "0") return "0"; //边界条件
        for(int i  = num1.size()-1; i >= 0; --i){
            int partial_sum = (num1[i] - '0') * ch_num + carry;
            carry = partial_sum / 10;
            int number = partial_sum % 10;
            res = to_string(number) + res;
        }
        if(carry > 0){
            res = to_string(carry) + res;
        }
        for(int i = 0; i < zero_num; ++i){
            res.push_back('0');
        }
        return res;
    }

    string strAdd(string &a, string &b){
        int carry = 0, a_idx = a.size() - 1, b_idx = b.size() - 1;
        string res;
        while(a_idx >= 0 || carry > 0 || b_idx >= 0){
            int a_val = 0, b_val = 0;
            if(a_idx >= 0){
                a_val = a[a_idx] - '0';
            }
            if(b_idx >= 0){
                b_val = b[b_idx] - '0';
            }
            int val = a_val + b_val + carry;
            //cout << "val: " << val << endl;
            carry = val / 10;
            int number = val % 10;
            res = to_string(number) + res;
            --b_idx; --a_idx;
        }
        return res;
    }
};
```

### 结果
执行用时 : 588 ms , 在所有 C++ 提交中击败了 5.04% 的用户 
内存消耗 : 60.5 MB , 在所有 C++ 提交中击败了 8.75% 的用户

### 方法二(借助vector)
1. 创建一个长度为a.size() + b.size()，并且元素全部为0的数组
2. 然后把所有部分和算到vector中
3. 进行进位的运算，将vector每一位变成单个digit
4. 将vector转为string
5. 去掉前面多余的0

```cpp
class Solution {
public:
    string multiply(string a, string b) {
        int n1 = a.size(), n2 = b.size();
        vector<int> v(n1 + n2, 0);
        for(int i = n1 - 1; i >= 0; --i){
            for(int j = n2 - 1; j >= 0; --j){
                v[i+j+1] += (a[i] - '0') * (b[j] - '0');
            }
        }
        int c = 0;
        for(int i = v.size() - 1; i >= 0; --i){
            v[i] += c;
            c = v[i] / 10;
            v[i] %= 10;
        }
        string res;
        for(int i = 0; i < v.size(); ++i){
            res += to_string(v[i]);
        }
        int i = 0;
        while(i < res.size()){
            if(res[i] != '0'){
                break;
            }else{
                res = res.substr(i+1, res.size() - i - 1);
            }
        }
        if(res.size() == 0) return "0";
        return res;
    }
};
```

### 结果
执行用时 : 12 ms , 在所有 C++ 提交中击败了 47.82% 的用户 
内存消耗 : 60.5 MB , 在所有 C++ 提交中击败了 100% 的用户
