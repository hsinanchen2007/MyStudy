
首先判断A和B哪个大，最大的数字减去2除以2必须小于等于最小的数字，否则错误
然后就是直接插入就可以了
```cpp []
class Solution {
public:
    string strWithout3a3b(int A, int B) {
        char maxC = 'a';
        int maxN = A;
        char minC = 'b';
        int minN = B;
        if (A < B) {
            maxC = 'b';
            maxN = B;
            minC = 'a';
            minN = A;
        }
        if ((maxN - 2) / 2 > minN) return "";
        string result(A + B ,  maxC);
        int temp = (maxN - 2) / 2 - minN;
        int count = 0;

        int start = 0;
        int index = 2;
        while (count < minN) {
            if (index  < result.size()) {
                result[index] = minC;
                index += 3;
                ++count;
            }
            else {
                start += 1;
                index = start;
            }
            
        
        }
        return result;
    }
};
```
![msedge_SuMnL2cXH2.png](https://pic.leetcode-cn.com/9f0b3982a97caaab6fa4f6408bc2bc7650ec90ff27283a97c4e5c07e0508399a-msedge_SuMnL2cXH2.png)

