参考了[@pris_bupt](/u/pris_bupt/)大佬的，只改了两个小细节，一是tmp插入dict[i]时直接插入，不寻找是否重复(利用set性质)，二是最后生成解时根据指向dict[target]的迭代器直接构建，不用for循环

```
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    if(candidates.size()==0)
            return {};
        unordered_map<int, set<vector<int>>> dict;
        for(int i=1;i<=target;i++){     //从1-target一步步求解法
            for(auto n:candidates){     //对于每一个可能的数字
                if(n == i)         //如果数字等于，则添加一种组合方法
                    dict[i].insert(vector<int> {n});
                else if(i > n){    // 说明i可以通过由n加上其他数组合而来
                    for(auto tmp:dict[i-n]){    //对于i-n的每一种组合方法
                        tmp.push_back(n);
                        sort(tmp.begin(), tmp.end());
                        dict[i].insert(tmp);
                    }
                }
            }
	    }
        vector<vector<int>> ret(dict[target].begin(), dict[target].end());
        return ret;
    }
};
```
