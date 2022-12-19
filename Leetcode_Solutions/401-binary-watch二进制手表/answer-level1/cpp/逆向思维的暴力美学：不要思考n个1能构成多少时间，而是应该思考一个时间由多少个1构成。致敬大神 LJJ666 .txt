```
class Solution {
public:
    //统计二进制中1的个数
    int count1(int n) 
    {
        int cnt = 0;
        while(n != 0) 
        {
            n = n & (n - 1);
            cnt++;
        }
        return cnt;
    }
    
    vector<string> readBinaryWatch(int num) 
    {
        vector<string> res;
        //遍历0:00到11:59的每个时间
        for(int i = 0; i < 12; i++) 
        {
            for(int j = 0; j < 60; j++) 
            {
                if(count1(i) + count1(j) == num) 
                {
                    res.push_back(to_string(i) + ":" + (j < 10 ? "0" + to_string(j) : to_string(j)));
                }
            }
        }
        return res;
    }
};
```