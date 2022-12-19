### 解题思路
这道题目其实是一道高中数学题目，f(x) = sinx, 把值域划分为numRows份，然后求出f(x)分别等于1, 1-1/numRows, 1-2/numRows, ..., -1时，x分别是多少。
这样可以看出，这道题目就是利用周期性来进行，周期T = 2 * (numRows - 1);
此外，我忽略了，当numsRows = 1的时候，以及string.size() >= numRows的情形，导致两次提交陷入了死循环。

### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.size();
        if(len <= numRows || numRows == 1) return s;
        int T = 2 * (numRows - 1);
        string res;
        for(int i = 0; i < numRows; ++i){
            //cout << "i: " << i << endl;
            int j = i, step = T - 2*i;
            if(step == 0){
                step = T;
            }
            while(j < len){
                //cout << "j: " << j << endl;
                res += s[j];
                j += step;
                if(step < T){
                    step = T - step;
                }
            }
        }
        return res;
    }
};
```