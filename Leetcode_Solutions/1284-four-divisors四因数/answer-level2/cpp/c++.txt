```
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            int jlen = nums[i];
            int flag = 4;
            int nsum = 0;
            for(int j = 1; j < jlen; j++)
            {
                if(nums[i]% j == 0)
                {
                    //cout << j << " " << nums[i]/j << " " << endl;
                    if(flag > 0)
                    {
                        jlen = nums[i]/j;
                        nsum += j;
                        flag --;
                        if(j != jlen)
                        {
                            nsum += jlen;
                            flag --;
                        }
                    }
                    else 
                    {
                        nsum = 0;
                        break;
                    }
                }
            }
            if(flag == 0)
            {
                //cout << nsum  << ",";
                sum += nsum;
            }
        }        
        
        return sum;
    }
};
```
