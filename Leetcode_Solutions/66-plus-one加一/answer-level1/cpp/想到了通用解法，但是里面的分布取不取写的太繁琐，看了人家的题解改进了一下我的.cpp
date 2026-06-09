### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len=digits.size()-1;
        vector<int>vec(digits.size()+1,0);
        vec[0]=1;
        for(int i=len;i>=0;i--){ 
            digits[i]++;   //注意：在外面实行递增，这一步关键
            if(digits[i]<=9)  //在里面直接返回
                return digits;
            if(digits[i]>9){ 
                digits[i]=0;
            }
        }
        return vec;
    }
};
```