### 解题思路
主要难点：
1、当低位存在很多9时，要一直向前进位直到某一位＋1不为10；
2、最高位若为9并且需要进位，记得在前面插入新的一位“1”。

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1;i>=0;i--){
            if(digits[i]!=9){
                digits[i]++;
                return digits;
            }
            else{
                digits[i]=0;
            }
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
};
```