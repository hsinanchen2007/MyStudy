### 解题思路
从末尾开始判断，如果为9，则末尾=0，上一位+1，循环判断

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    int n=digits.size();
    int i;
if (digits[n-1]!=9) digits[n-1]+=1;
else if (digits[n-1]==9) digits[n-1]+=1;
for(i=n-1;i>0;i--)
{
    if(digits[i]==10) 
    {
    digits[i]=0;
    digits[i-1]+=1;
    }
}

if(digits[0]==10) 
{digits[0]=0;
digits.insert(digits.begin(),1);}

return digits;
 }
    
 };
```