### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0;
        for(int i = 0; i < A.size(); i++){
            sum += A[i];
        }
        int ans=A[0],count=0;
        if(sum % 3 != 0){
            return false;
        }
        int k = sum / 3;
        for(int i = 1; i < A.size(); i++){
            if(ans == k && count < 2){
                ans = 0;
                count++;
            }
            ans += A[i];
        }
        if(ans == k && count == 2){
            return true;
        }else{
            return false;
        }
    }
};
```