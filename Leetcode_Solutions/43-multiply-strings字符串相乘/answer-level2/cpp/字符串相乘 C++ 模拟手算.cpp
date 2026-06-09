### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string multiply(string num1, string num2) {
        // m位数乘以n位数，结果最多为m+n位数
        int allLen = num1.size() + num2.size();
        // 初始化int数组，长度为allLen，元素初始化为0
        vector<int> tmpResult(allLen, 0);
        // 返回的结果
        string result(allLen, '0');
        // 模拟手算从最后一位开始处理
        for (int i = num1.size() - 1; i >= 0; i--) {
            for (int j = num2.size() - 1; j >= 0; j--) {
                tmpResult[i + j + 1] += (num1[i] - '0')*(num2[j] - '0');
            }
        }
        // 进位
        for (int i = allLen - 1; i>0; i--) {
            if (tmpResult[i] > 9) {
                tmpResult[i - 1] += tmpResult[i] / 10;
                tmpResult[i] %= 10;
            }
        }
        // 转换成字符串
        for (int i = allLen - 1; i >= 0; i--) {
            result[i] = tmpResult[i] + '0';
        }
        if (result.find_first_not_of('0') == string::npos) {
            // 排除全0的情况 
            return "0";
        }
        return result.substr(result.find_first_not_of('0'), string::npos);
    }
};

/*================================================================================================================
            num2[j]                             num2[0]             num2[1]             num2[2]
     *      num1[i]                             num1[0]             num1[1]             num1[2]
     --------------------------------------------------------------------------------------------------------------
                                                num2[0]*num1[2]     num2[1]*num1[2]     num2[2]*num1[2]
                              num2[0]*num1[1]   num2[1]*num1[1]     num2[2]*num1[1]
            num2[0]*num1[0]   num2[1]*num1[0]   num2[2]*num1[0]
     --------------------------------------------------------------------------------------------------------------                 tmpresult[1]      tmpresult[2]      tmpresult[3]        tmpresult[4]        tmpresult[5]
=================================================================================================================*/


#include <iostream>
#include <vector>
#include <string>

using namespace std;

string multiply(string num1, string num2) {
    int allLen = num1.size() + num2.size();
    vector<int> tmpResult(allLen, 0);
    string result(allLen, '0');
    for (int i = num1.size() - 1; i >= 0; i--) {
        for (int j = num2.size() - 1; j >= 0; j--) {
            tmpResult[i + j + 1] += (num1[i] - '0')*(num2[j] - '0');
        }
    }
    for (int i = allLen - 1; i>0; i--) {
        if (tmpResult[i] > 9) {
            tmpResult[i - 1] += tmpResult[i] / 10;
            tmpResult[i] %= 10;
        }
    }
    for (int i = allLen - 1; i >= 0; i--) {
        result[i] = tmpResult[i] + '0';
    }
    if (result.find_first_not_of('0') == string::npos) {
        return "0";
    }
    return result.substr(result.find_first_not_of('0'), string::npos);
}

int main() {
    string s1 = "123";
    string s2 = "456";
    cout << multiply(s1, s2) << endl;
}
            
```