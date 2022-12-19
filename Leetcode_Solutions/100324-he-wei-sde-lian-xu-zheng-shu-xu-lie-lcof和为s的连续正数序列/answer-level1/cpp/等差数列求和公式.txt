### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        if(target < 3)return {};  //target=1，不满足条件；target=2，不满足条件
        //由等差数列求和公式: target=na_1 + n(n-1)/2，a_1为首项，1为公差
        //反解出首项a_1=(target-n(n-1)/2)/n，其中n>=2为题目条件, a_1>0，正整数也为题目条件
        //若存在满足上述条件的正整数a_1，那a_1开始往后添加n项
        vector<vector<int>> res;
        for(int n = 2; n < target; ++n)  //n表示项数
        {
            int temp = target - n*(n-1)/2;  //这个肯定是整数
            if(temp <= 0)break;  //不得为负数！！！直接break!!!
            if(temp % n == 0)
            {
                //说明a_1 = (target-n(n-1)/2)/n得到的是正整数，a_1是首项
                int a_1 = temp / n;
                vector<int> tempVec;
                tempVec.push_back(a_1);
                for(int i = 1; i < n; ++i)
                    tempVec.push_back(a_1 + i);
                res.push_back(tempVec);
            }
        }
        return vector<vector<int>>(res.rbegin(), res.rend());  //最后倒序输出以满足题目条件
    }
};
```