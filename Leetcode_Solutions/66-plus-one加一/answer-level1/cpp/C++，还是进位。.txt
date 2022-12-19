### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int m=digits.size();
        int bit(0);
        bit=(digits[m-1]+1)/10;//bit计算在前
        digits[m-1]=(digits[m-1]+1)%10;
        for(int i=m-2;i>=0;--i){
            int tmp=digits[i]+bit;
            digits[i]=tmp%10;
            bit=tmp/10;
        }
        if(bit)//还有进位
            digits.insert(digits.begin(),bit);
        return digits;
    }
};
```