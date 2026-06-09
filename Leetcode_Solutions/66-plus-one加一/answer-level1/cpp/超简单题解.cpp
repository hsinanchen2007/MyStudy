vector原来是可以动态变化长度的。
`digit.insert(digit.begin(),1)`就是在开头新增一个元素，原数组的长度动态加一。
一开始还思考怎么把数组长度加一，后来看了别人的题解才明白^^

思路:
1. 从后往前遍历数组，如果一直是9，就把当前位变成0；直到出现不是9的位或者到了第一位
2. 如果第一位也是9，就在第一位插入1
3. 如果第一位不是9，或者当前位不是第一位，就把当前位+1 

```
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size()-1;
        while(n>0 && digits[n]==9){
                digits[n]=0;
                n--;
        }
        if(n==0 && digits[0]==9)//到了开头仍然是9
        {
            digits[0]=0;
            digits.insert(digits.begin(), 1);
        }
        else
            digits[n]++;
        return digits;
    }
};
```
