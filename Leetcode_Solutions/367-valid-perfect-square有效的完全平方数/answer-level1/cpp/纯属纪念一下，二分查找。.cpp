### 解题思路
执行用时 : 0 ms , 在所有 C++ 提交中击败了 100.00% 的用户 
内存消耗 : 7.6 MB , 在所有 C++ 提交中击败了 100.00% 的用户

### 代码

```cpp
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num ==1){
            return true;
        }
        int begin = 1;
        int end = num/2;
        while(begin<=end){
            long long mid = (begin +end)/2;
            long long temp = mid *mid ;
            if(temp == num){
                return true;
            }
            else if(temp < num ){
                begin = mid +1;
            }
            else{
                end = mid -1;
            }
        }
        return false;
    }
};
```