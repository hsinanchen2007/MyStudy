### 解题思路
从后往前遍历数组，判断最后一位是否为9，因为为9的话+1要进位，如果进位了，接着判断前一位是否为9，直到不为9的这一位为止。如果整个数组都是9，那么就在首位插入1，其他位均置为0.

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len=digits.size();
        for(int i=len-1;i>=0;i--)
        {
            if(digits[i]==9)
            {
                digits[i]=0;
                if(digits[0]==0)
                {digits.insert(digits.begin(),1);}
                continue;
            }
            else
            {
                digits[i]+=1;
                break;
            }

        }
        return digits;
    }
};
```