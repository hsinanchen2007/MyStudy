```
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int tmp[2]{0,0};
        for(int b: bills)
        {
            switch(b)
            {
                case 5:
                {
                    ++tmp[0];
                    break;
                }
                case 10:
                {
                    if(tmp[0]>0)
                    {
                        ++tmp[1];
                        --tmp[0];
                    }
                    else
                    {
                        return false;
                    }
                    break;
                }
                case 20:
                {
                    if(tmp[1]>0)
                    {
                        if(tmp[0]>0)
                        {
                            --tmp[0];
                            --tmp[1];
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else if(tmp[0]>2)
                    {
                        tmp[0]-=3;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
```
