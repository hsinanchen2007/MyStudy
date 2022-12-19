### 解题思路
估计代码还有很多可以优化的地方

主要思路：
1.  对输入的数组排序
2.  关键在这，每一次递归返回之后都要需要跳过和当前数字相同的元素，否则会出现重复组合

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;

        sort(candidates.begin(),candidates.end());

        vector<int> tmp;

        auto startIt = candidates.begin();
        while (startIt != candidates.end() ) {
            findNextOne(res,candidates,startIt,tmp,0,target);

            int current = *startIt;
            //关键在这，每一次递归返回之后都要需要跳过和当前数字相同的元素，否则会出现重复组合
            while ( ++startIt != candidates.end() && *startIt == current) {

            }
        }

        return res;
    }

    bool findNextOne(vector<vector<int>>& res,vector<int>& candidates, vector<int>::iterator startIt,vector<int>& tmp,int sum,int target)
    {
        int current = *startIt;
        sum += current;
        tmp.push_back(current);

        if( sum == target )
        {
            res.push_back(tmp);
        }
        else if( sum < target )
        {
            while (++startIt != candidates.end() ) {
                if(!findNextOne(res,candidates,startIt,tmp,sum,target))
                {
                    tmp.erase(tmp.end()-1);
                    return true;
                }
                current = *startIt;
                //关键在这，每一次递归返回之后都要需要跳过和当前数字相同的元素，否则会出现重复组合
                while ( ++startIt != candidates.end() && *startIt == current) {

                }
                --startIt;
            }
        }
        else
        {
            tmp.erase(tmp.end()-1);
            return false;
        }
        tmp.erase(tmp.end()-1);
        return true;
    }
};
```