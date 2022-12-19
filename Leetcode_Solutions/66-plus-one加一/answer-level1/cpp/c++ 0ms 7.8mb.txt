![捕d.PNG](https://pic.leetcode-cn.com/aa1d4de039858cec10cc8711d2708e15ae195fce20a2cfe84f64efc4321208e0-%E6%8D%95d.PNG)
```
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool flag=1;
        for(int i=digits.size()-1;i>=0;--i){
            if(flag+digits[i]>=10){
                digits[i]=(flag+digits[i])%10;
                flag=1;
            }
            else {
                    digits[i]=(flag+digits[i]);
                    flag=0;
            }
        }
        if(flag) { digits.insert(digits.begin(),1);return digits;}
        return digits; 
    }
};
```

