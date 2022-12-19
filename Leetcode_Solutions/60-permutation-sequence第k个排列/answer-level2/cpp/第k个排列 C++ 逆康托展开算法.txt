### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    /*
    输入: n = 4, k = 9
    输出: "2314"
    */
    string getPermutation(int n, int k) {
        // 逆康托展开算法
        string data = "0123456789";
        // 保存阶乘
        int f[n+1];
        // 0的阶乘初始化为1
        f[0] = 1;
        // 计算出各个阶乘，f[n]=n!
        for (int i=1; i<=n; i++) {
            f[i] = f[i-1] * i;
        }
        string res = "";
        while (k >= 1 && n) {
            int pos = (k) / f[n-1];
            if (k % f[n-1] != 0) {
                pos++;
            }
            k = k-(pos-1)*f[n-1];
            res = res + (data[pos]);
            data.erase(pos, 1);
            n--;
        }
        return res;
    }
};
// https://blog.csdn.net/ajaxlt/article/details/86544074




#include <iostream>
#include <vector>

using namespace std;

string getPermutation(int n, int k) {
    string data = "0123456789";
    int f[n+1];
    f[0] = 1;
    for (int i=1; i<=n; i++) {
        f[i] = f[i-1] * i;
    }
    string res = "";
    while (k >= 1 && n) {
        int pos = (k) / f[n-1];
        if (k % f[n-1] != 0) {
            pos++;
        }
        k = k-(pos-1)*f[n-1];
        res = res + (data[pos]);
        data.erase(pos, 1);
        n--;
    }
    return res;
}

int main() {
    cout << getPermutation(3, 3) << endl;
}




```