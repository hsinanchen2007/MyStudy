```
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count1 = 0;
        int count2 = 0;
        for(int i = 0; i < bills.size(); i++)
        {

            if(bills[i] == 5)
            {
                count1++;
            }
            else if(bills[i] == 10)
            {
                count2++;
                count1--;
            }
            else{
                if(count2 != 0)
                {
                    count1--;
                    count2--;
                }
                else{
                    count1-=3;
                }
            }
            if(count1 < 0 || count2 < 0)
                return false;
        }

        return true;
    }
};
```
