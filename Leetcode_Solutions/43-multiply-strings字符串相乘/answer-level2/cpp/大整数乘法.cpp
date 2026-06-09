### 解题思路


超过所有数值类型的最大值上限，按照我们的乘法笔算思路去完成，结果最大长度是两个字符串的长度和，9 * 9 最大81两位数

每次小组相乘直接落入结果位，注意有高低位的情况，高位为i + j, 低位i + j + 1

设置一个结果最高位的标志位，并在循环中更新，可以更快的找到结果字符串的开始。标志为起始位置为结果vector的最后位置

执行用时 :
4 ms, 在所有 C++ 提交中击败了97.08%的用户
内存消耗 :
8 MB, 在所有 C++ 提交中击败了100.00%的用户


### 代码

```cpp
class Solution {
public:
    string multiply(string num1, string num2) {

        int len1 = num1.length();
        int len2 = num2.length();
        vector<int> res(len1+len2, 0);
        string m_res;
        int max_pos = len1+len2 - 1;// 设置一个标志位标志结果字符串的最高位

        for(int i = len2 - 1; i > -1 ; i--){
            for(int j = len1 - 1; j > -1; j--){
                int pos_low = i + j + 1;// 每一小组的乘积低位和高位
                int pos_high = i + j;

                int m = (num2[i] - '0') * (num1[j] - '0') + res[pos_high] *  10 + res[pos_low];
                res[pos_high] = m / 10;
                res[pos_low] = m % 10;

                if(pos_high < max_pos && res[pos_high] != 0){//更新最高位位置
                    max_pos = pos_high;
                }else if(pos_low < max_pos && res[pos_low] != 0){
                    max_pos = pos_low;
                }
            }
        }

        for(int k = max_pos; k < (int)res.size(); k++){
            m_res.push_back(res[k] + '0');
        }
        return m_res;
    }
};
```