### 解题思路
模拟竖式乘法，注释详尽，思路参考以下题解：
https://leetcode-cn.com/problems/multiply-strings/solution/ji-bai-100-by-nuo-33/

![截屏2020-03-17下午11.47.44.png](https://pic.leetcode-cn.com/670f60931b5e35d75b96c1151e23fc53b665ce5b724b7fc53470664560e9a45a-%E6%88%AA%E5%B1%8F2020-03-17%E4%B8%8B%E5%8D%8811.47.44.png)

### 代码

```cpp
class Solution {
public:
    string multiply(string num1, string num2) {
        //遇0返回
        if(num1[0] == '0' || num2[0] == '0'){
            return "0";
        }

        //两个字符串需头尾调换一下位置方便从个位开始进行竖式乘法
        reverse(num1.begin(), num1.end());
        reverse(num1.begin(), num1.end());

        int l1 = num1.length();
        int l2 = num2.length();

        //竖式乘法
        int ans[l1+l2]={0}; //初始化结果数组为0，长度为num1和num2的位数总和
        //num1在竖式的上方，num2在下方, 将num1与num2的每一位相乘并求每一位的和，暂时不进位
        for(int j = 0; j < l2; j++){
            int k=j+1;
            for(int i = 0; i < l1; i++){
                ans[k] += (num1[i]-'0') * (num2[j]-'0');
                k++;
            }
        }

        //由后往前进位
        for(int i = (l1+l2-1); i >= 0; i--){
            if(ans[i] >= 10){
                ans[i-1] += ans[i] / 10;
                ans[i] = ans[i] % 10;
            }
        }

        //转字符串
        string res = "";
        for(int i = 0; i < (l1+l2); i++){
            if(i == 0 && ans[i] == 0){
                continue;
            } else{
                res += ('0'+ans[i]);
            }
        }

        return res;
    }
};
```