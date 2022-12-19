### 解题思路
思路很简单，就是：
如果 temp（当前位+1）> 10 则当前为替换为 temp%10
如果 temp < 10 则终止循环

特殊情况9999999，等考虑为最后一次循环temp仍然为10，则给result最前面加一；


### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        vector<int> result(digits);
        
        for (auto i = size-1;i >-1;i--)
        {
            int temp = digits[i] + 1;
            result[i] = (temp % 10);
            if (temp < 10)
                break;
            if (temp >= 10 &&i==0)
                  result.insert(result.begin(),1);          
        }
            


        return result;
    }
    
};
```