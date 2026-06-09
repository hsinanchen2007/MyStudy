### 解题思路
仔细了解清题目！！!
题目中每次都是加一，所以进位的情况只能是9->10，进位
第一种方法时先加一后进行判断进位，第二种方法时先判断是否需要进位再进行加一，显然第二种更加简便.


### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1; i>=0; i--){
            if(digits[i]==9)
                digits[i]=0;
            else{
                digits[i]++;
                return digits;
            }
        }
        digits.push_back(0);
        digits[0]=1;
        return digits;
    }
};
```