- DFS
如果当前元素小于`target`，则继续向后搜索，否则添加结果集，退出递归。
难点在于保存整个`path`数组：声明一个全局变量`path`，用来存储当前路径，在递归调用完事之后再`pop`，可以保证`path`数组不会乱。


```
// class Solution {
// public:
//     vector<int>path;
//     void helper(int index, int target, vector<vector<int>>& res, vector<int>& candidates){
//         if(target==0){//递归结束条件
//             res.push_back(path);
//             return;
//         }
//         for(int i=index;i<candidates.size();i++){
//             if(target-candidates[i]<0)break;//i后边的不再考虑
//             path.push_back(candidates[i]);
//             helper(i,target-candidates[i],res,candidates);
//             path.pop_back();
//         }
//     }
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<vector<int>>res;
//         sort(candidates.begin(),candidates.end());//排序，有利于剪枝
//         helper(0,target,res,candidates);
//         return res;
//     }
// };
```

- 动态规划
首先想到的想法，但是时间复杂度和空间复杂度太高了。所以仅供参考

```
//dp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        unordered_map<int,set<vector<int>>>map;
        vector<vector<int>>res;
        set<vector<int>>::iterator it;
        sort(candidates.begin(),candidates.end());
        for(int i=0;i<=target;i++){
            for(auto item:candidates){
                if(i<item)break;
                if(i==item)map[i].insert({i});//当前元素等于target，直接在对应的map[i]集合中插入
                for(it=map[i-item].begin();it!=map[i-item].end();it++){//依次查找在map[i-item]集合中添加item插入map[i]的集合
                    vector<int>temp=*it;
                    temp.push_back(item);//map[i-item]的结果再加上当前循环的item
                    sort(temp.begin(),temp.end());//不排序不会去重
                    map[i].insert(temp);
                }
            }
        }
        for(it=map[target].begin();it!=map[target].end();it++){
            res.push_back(*it);
        }
        return res;
    }
};
```