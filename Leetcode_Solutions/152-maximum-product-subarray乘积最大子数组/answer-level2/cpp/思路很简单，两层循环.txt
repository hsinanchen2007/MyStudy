+ 首先对特殊情况，num.size()==0||num.size()==1进行处理。如果nums为空，返回0；如果只有一个数，返回那个唯一的数即可。
+ 当num.size()>=2时，初始化max=-∞，i从2开始，递增到n结束，j从i开始，递增到n结束。如此循环可以得出以nums[i]为开始的子序列的乘积。当子序列的乘积大于最大值时，令最大值等于子序列的乘积即可。

不知道怎么插入图片欸，详情见 https://www.irene.ink/archives/148/

```cpp
class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        else if(n==1){
            return nums[0];
        }
        int max = INT_MIN;
        int tmp;
        for (int i  = 0; i < n; i++) {
            tmp=1;
            for (int j =i; j < n; j++) {
                tmp = nums[j] * tmp;
                if (max < tmp) {
                    max = tmp;
                }
            }
        }
        return max;
    }
};
```