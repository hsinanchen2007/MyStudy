
- 思路： 
- 从后向前，找到第一个不为9的数，该位+1，该位后的数均变为0；
- 未找到的话，说明该数全为9，则返回 1 加 digits.size()个0

```
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len=digits.size();        
        for(int i=len-1;i>=0;i--)  //从后向前
        {
            //找到第一位不为9的，该位+1，该位后面的均变为0
            if(digits[i]!=9) 
            {
                digits[i]+=1;                
                for(int j=i+1;j<len;j++)
                    digits[j]=0;
                return digits;
            }else  //digits[i]==9 继续往前找不等于9的
                continue;       
        }
        
        //上面没找到不等于9的，说明是99999...,返回100000...        
        vector<int> ans(len, 0);
        ans.insert(ans.begin(),1);
        return ans;
    }
};
```