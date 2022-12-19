## 暴力法：两层循环
错误点：
1、重复利用了这个数组中同样的元素；
2、本想减少遍历成本，缺遗漏了负值的情况：
 if(nums[i] > target) continue;
```
vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int i,j;
        for(i=0; i<nums.size()-1; i++)
        {
            for(j=i+1; j<nums.size(); j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        return res;
    }
```

## 遍历两遍哈希表
```
vector<int> twoSum(vector<int>& nums, int target) {
        int i, len = nums.size();
        vector<int> res;
        map<int,int> mm;
        for(i=0; i<len; i++)
        {
            mm[nums[i]] = i;
        }

        for(i=0; i<len; i++)
        {
            int x = target-nums[i];
            if( mm.find(x) != mm.end() && mm[x] != i )
            {
                res.push_back(i);
                res.push_back(mm[x]);
                return res;
            }
        }
        return res;
    }
```

## 遍历一遍哈希表
插入哈希表的时候就可以找，只不过找到的值顺序是反过来的
```
vector<int> twoSum(vector<int>& nums, int target) {
        int i, len = nums.size();
        vector<int> res;
        map<int,int> mm;
        for(i=0; i<len; i++)
        {
            int x = target-nums[i];
            if( mm.find(x) != mm.end())
            {
                res.push_back(mm[x]);
                res.push_back(i);
                return res;
            }
            mm[nums[i]] = i;
        }
        return res;
    }
```