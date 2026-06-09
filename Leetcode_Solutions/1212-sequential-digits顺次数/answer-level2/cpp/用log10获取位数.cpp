
![捕获.PNG](https://pic.leetcode-cn.com/8a9e53d3742e638e37ac58cf7c95ac64faea80775dbc8060859ebefcbf70f4a0-%E6%8D%95%E8%8E%B7.PNG)


```
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        int low_bit = log10(low)+1;
        int high_bit = log10(high)+1;
        for(int mbit = low_bit; mbit<=high_bit;mbit++)
        {
            for(int i=1;i<=10-mbit;i++)
            {
                int temp_num = 0;
                for(int j=0; j<mbit;j++)
                {
                    temp_num = temp_num + (i+j)*pow(10, mbit-j-1);
                }
                if(temp_num>=low)
                {
                    if(temp_num<=high)
                        res.push_back(temp_num);
                    else
                        break;
                }
            }
        }
        return res;
    }
};
```
