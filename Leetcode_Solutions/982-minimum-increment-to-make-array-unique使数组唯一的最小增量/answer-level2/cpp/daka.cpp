内存消耗略大。。

线探，时间还行
```
class Solution {
public:
    int minIncrementForUnique(vector<int>& A)
    {
        int v[40000] = {0};
        for(int i = 0; i < A.size(); i++)
            v[A[i]]++;

        int ans = 0, counter = 0, i = 0;
        while(i < 40000)
        {
            if(v[i] == 0)
            {
                if(counter > 0)
                    counter--;
            }
            else if(v[i] > 1)
            {
                counter += v[i] - 1;
            }
            ans += counter;
            i++;
        }
        if(counter > 0)
            ans += (counter - 1) * counter / 2;

        return ans;	
    }
};
```
