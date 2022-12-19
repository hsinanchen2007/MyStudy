之前用的是DFS做的，会超时，后来看了他人的写法，发现有很巧的做法，利用余数是1还是2，分别去删除

```
class Solution {
    bool del(vector<int>& digits, int val)
    {
        
        for(int i = digits.size() - 1; i >= 0; i--)
        {
            if(digits[i] % 3 == val)
            {
                digits.erase(digits.begin() + i);
                return true;
            }
        }
        return false;
    }
public:
    string largestMultipleOfThree(vector<int>& digits) {
        if(!digits.size()) return "";
        sort(digits.begin(), digits.end(), greater<int>());
        int zeros = 0 , sum = 0;
        for(auto x: digits)
        {
            sum += x;
            if(!x) zeros++;
        }

        if(sum % 3 == 0) 
        {

        }
        else if(sum % 3 == 1)
        {
            if(del(digits, 1)){}
            else{
                bool b = del(digits,2) && del(digits,2);
                if(!b) return zeros? "0":""; 
            }
        }
        else if(sum % 3 == 2)
        {
            if(del(digits,2)){}
            else{
                bool b = del(digits, 1) && del(digits, 1);
                if(!b) return zeros? "0":"";
            }
        }
        if(digits[0] == 0) return "0";
        string res = "";
        for(int i = 0; i < digits.size(); i++)
        {
            res += digits[i] + '0';
        }
        return res;
    }
};
```
