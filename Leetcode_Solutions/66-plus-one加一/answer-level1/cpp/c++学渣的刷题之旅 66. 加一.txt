```c++
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int j=1,t;
        for(int i=digits.size()-1;i>=0;i--){
            t=(digits[i]+j)%10;
            j=(digits[i]+j)/10;
            digits[i]=t;       
        }
        if(j>0){
            digits.insert(digits.begin(),j);
        }
        return digits;
    }
};
```
用 j 表示进位，t 表示当前位置临时值，循环完后，如果 j > 0 说明最前面进位了，则在开头插入。（需要了解vector插入方法）