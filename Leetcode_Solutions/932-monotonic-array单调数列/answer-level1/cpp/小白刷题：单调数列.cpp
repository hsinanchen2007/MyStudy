没想到开头结尾的方法，笨方法处理

等值是不影响数列变化趋势的，遍历比较两数大小是否与趋势不同

代码：
```
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int len = A.size();
        if(len >= 3) {
            bool up = false;
            bool equal = true;
            for(int i = 1 ; i < len ; i++) {
                if(A[i] != A[i - 1]) {
                    if(equal) {
                        equal = false;
                        up = A[i] > A[i - 1];
                    }
                    else {
                        if((A[i] > A[i - 1]) ^ up)
                            return false;
                    }
                }
            }
        }
        return true;
    }
};
```
