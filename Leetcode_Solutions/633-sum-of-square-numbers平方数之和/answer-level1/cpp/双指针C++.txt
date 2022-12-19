执行用时 : 4 ms , 在所有 cpp 提交中击败了 92.18% 的用户 内存消耗 : 8 MB , 在所有 cpp 提交中击败了 85.00% 的用户
```
class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int left = 0;
        long long int right = sqrt(c) + 1;
        while(left <= right){
            long long int sum = left * left + right *right;
            if (sum < c) {
                left ++;
            } else if (sum > c){
                right --;
            }  else {
                return true;
            }
        }
        return false;
    }
};
```
