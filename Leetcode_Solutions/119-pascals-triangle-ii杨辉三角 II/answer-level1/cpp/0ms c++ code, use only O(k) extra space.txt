### My code are here:
```
//Currently the code is easy to understand. But Pascal`s Triangle is symmetrical, we can optimize the code.
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> kth_row(rowIndex+1, 1); //kth row of Pascal`s Triangle has k+1 elements.
        for(int row=2; row<=rowIndex; row++) // fill up the first 2 row with 1s.
        {
            for(int col=row-1; col>0; --col) // Calculate from the front will lead to override.
            {
                kth_row[col]=kth_row[col]+kth_row[col-1];
            }
        }
        return kth_row;
    }
};
```
---
ps. 我想锻炼下英语表达能力 :)