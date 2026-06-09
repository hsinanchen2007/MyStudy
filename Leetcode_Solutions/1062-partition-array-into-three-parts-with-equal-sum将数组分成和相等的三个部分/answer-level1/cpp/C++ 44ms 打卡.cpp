### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0;
        for(int num : A) sum += num;
        if(sum % 3 != 0) return false;
        else sum /= 3;
        int res = sum, flag = 3;
        for(int num : A){
            if(flag == 1) return true;
            res -= num;
            if(res == 0){
                res = sum;
                flag--;
            }
        }
        return flag <= 0 ? true : false;
    }
};
```