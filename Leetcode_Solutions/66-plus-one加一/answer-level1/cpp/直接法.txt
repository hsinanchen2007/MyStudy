### 解题思路
此处撰写解题思路
先将数组digits反转（reverse）便于计算，将digits[0]++，然后循环i：0-n-2；如果digits[i]==10,就进位
### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int n=digits.size();
        int i,j;
        digits[0]++;
        for(i=0;i<n-1;i++){
            if(digits[i]!=10)break;
            else{
                digits[i+1]++;
                digits[i]=0;
            }
        }
        if(digits[n-1]==10){
            digits[n-1]=0;
            digits.push_back(1);
        }
        reverse(digits.begin(),digits.end());
        return digits;
    }
};
```