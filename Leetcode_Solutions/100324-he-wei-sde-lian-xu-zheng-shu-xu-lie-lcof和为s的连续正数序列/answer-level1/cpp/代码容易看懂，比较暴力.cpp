
直接暴力遍历，感觉逻辑比较简单，原谅我只想到这个

```
    int sum(int x,int target)//累加求和 看是否有满足条件值
    {
        for (int i = x+1; x < target; ++i)
        {
            x += i;
            if (x == target) return i;//返回数组最大值
        }   
        return 0;
    }

    vector<vector<int>> findContinuousSequence(int target) 
    {
        vector<vector<int>> ret;
        for (int i = 1; i <= target/2; ++i)
        {
            int flag = sum(i, target);
            if (flag)
            {
                vector<int> tmp;
                for (int j = i; j <= flag; ++j)
                {
                    tmp.push_back(j);
                }
                ret.push_back(tmp);
            }
        }
        return ret;
    }
```
