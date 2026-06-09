### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>::iterator it = digits.end();
        int mode;
        while(it!=digits.begin()){
            it--;
            *it = *it+1;
            if(*it == 10){
                *it = 0;
            }else {break;}
        }
        if(*digits.begin() == 0){
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};
```