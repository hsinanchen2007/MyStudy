### 解题思路
注意进位和补位！

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if(n==1 && digits[0]==9) return {1,0};
        for(int i=n-1; i>=0; i--){
            if(i==n-1 && digits[i]+1 < 10){
                digits[i] += 1;
            }
            else{
                if(i==n-1){
                    digits[i] = digits[i]+1-10;
                    if(i>0) digits[i-1] += 1;
                }
                else if(i>0 && digits[i] > 9){
                    digits[i] = digits[i]-10;
                    digits[i-1] += 1;
                }
                if(digits[i] > 9 && i == 0){
                    digits[i] = digits[i]-10;
                    digits.insert(digits.begin(), 1);
                }
            }
        }
        return digits;
    }
};
```