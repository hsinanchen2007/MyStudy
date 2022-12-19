### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxTurbulenceSize2(vector<int>& A) {
        if(A.size() < 2)
            return A.size();
        int lastSign = 0;    // 记录上一个状态
        bool start = true;   // 标志是否为开始状态
        int maxLen = 1, result = 1;
        for(int i = 1; i < A.size(); i++){
            int tmp = A[i] == A[i - 1] ? 0 : (A[i] > A[i - 1] ? 1 : -1); // 难点在于状态 0 的处理
            if(tmp == 0){                                  // 特殊状态是 0，此时不符合湍流规则，置为开始状态，长度变成 1
                start = true;
                maxLen = 1;
            }else if(start == true || lastSign * tmp < 0){ // 若为开始状态 或者 新状态与上一状态不同
                start = false;
                maxLen += 1;                               // 则长度加 1
            }else{                                         // 否则，新状态与上一状态相同，长度变成 2
                start = false;
                maxLen = 2;
            }
            lastSign = tmp;                                // 设置新状态：1、-1、0
            if(result < maxLen){
                result = maxLen;
            }
        }
        return result;
    }
    int compare(int a, int b){
        return a < b ? -1 : a == b ? 0 : 1;
    }
    int maxTurbulenceSize(vector<int>& A){ // 滑动窗口
        int len = A.size();
        if(len < 2)
            return len;
        int left = 0, right = 1; //初始化窗口边界
        int result = 1;
        while(right < len){
            int tmp = compare(A[right - 1], A[right]);
            //到达数组末尾或者湍流不成立时，开始划分窗口
            if(right == len - 1 || tmp * compare(A[right], A[right + 1]) != -1){
                // 若当前值与前一个值不同，则更新结果
                if(tmp != 0)
                    result = max(result, right - left + 1); // 计算窗口大小
                left = right; //窗口左边界右移
            }
            right ++;
        }
        return result;
    }
};
```