```
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills.size() == 0)
            return true;
        
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        bool res = true;
        for(int i=0;i<bills.size();i++)
        {
            if(bills[i] == 5)
            {
                cnt1++;
            }
            else if(bills[i] == 10)
            {
                if(cnt1 >= 1)
                {
                    cnt2++;
                    cnt1--;
                }
                else
                {
                    return false;
                }
            }
            else if(bills[i] == 20)
            {
                if(cnt2 >= 1 && cnt1 >= 1)
                {
                    cnt3++;
                    cnt2--;
                    cnt1--;
                }
                else if(cnt1 >= 3)
                {
                    cnt3++;
                    cnt1-=3;
                }
                else
                {
                    return false;
                }
            }
        }
        return res;
    }
};
```