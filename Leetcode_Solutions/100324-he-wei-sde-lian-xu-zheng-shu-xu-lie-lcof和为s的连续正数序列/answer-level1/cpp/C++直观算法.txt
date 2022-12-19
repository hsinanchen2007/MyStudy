### 解题思路
外层循环首位数字从1开始递增，内层循环为连续数字总和，注意边界判断即可

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>>res;
        if(target<3)
            return res;
        int fir=1;
        while(fir<=target/2)
        {
            int sum=0;
            int temp=fir;
            vector<int>list;
            while(sum<target)
            {
                list.push_back(temp);
                sum+=temp++;
                if(sum==target)
                    res.push_back(list);
            }
            fir++;

        }
        return res;
    }
};
```