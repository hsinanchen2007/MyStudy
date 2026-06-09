-  思路：从末位向前逐位模拟十进制加法器，首位进行单独判断

-  结果：不知道测评算法是什么，代码不变，提交四次结果均不一样，`四次取平均`下来耗时2ms, 内存占用7.8m，其中两次均击败100%，

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        for(int i = size - 1; i >= 0; --i){
            if(digits[i] < 9){
                ++digits[i];
                return digits;
            }
            if(i == 0){
                digits[i] = 1;
                digits.push_back(0);
            }
            else
                digits[i] = 0;
        }
        return digits;
    }
};
```
喜欢给点个赞吧，一起fight！