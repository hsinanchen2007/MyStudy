### 解题思路
此处撰写解题思路
这个题目关键就是判断当前位置是否为9，是9的话就要向前继续加1，而当前位置肯定是0.
特别情况就是类似9、99、999这种，需要在vector的开始位置插入一位，digits.insert(digits.begin(),1)

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        for(int i=digits.size()-1;i>=0;i--){
            if(digits[i]<9){
                digits[i] +=1;
                break;
            }else{
                digits[i] =0;
                if(i==0){
                    digits.insert(digits.begin(),1);
                }
            }
            
        }
        return digits;
        
    }
};
```