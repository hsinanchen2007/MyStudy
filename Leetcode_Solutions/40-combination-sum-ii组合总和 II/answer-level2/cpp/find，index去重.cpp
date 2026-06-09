### 解题思路
这道题和上一道题差不多，就是多了一个降重。
首先想到的是用find函数找res是否已经有了temp 结果时间太长了，

然后发现题目是不允许在同一个for循环里有相同的数。不会关心迭代进去后的数和前面是否相等，所以用了if(i!=index&&candidates[i]==candidates[i-1]) continue;

最后看解题发现一个更巧妙的方法，首先把for改为while，可以减少迭代次数，最重要的是用了 
combinationSum2Core(candidates, target-candidates[index++], index, temp, res);
while(index<candidates.size()&&candidates[index]==candidates[index-1]) ++index;
来降重，target-candidates[index++]表示target-candidates[index]和index-1.他后面的index就跟着变了，

### 代码

```cpp
class Solution {
public:
    // 执行用时 :120 ms, 在所有 C++ 提交中击败了10.33% 的用户
    // 内存消耗 :7 MB, 在所有 C++ 提交中击败了100.00%的用户
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if(candidates.size()==0) return res;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());//先对数组排序。
        combinationSum2Core(candidates, target, 0, temp, res);
        return res;
    }
    void combinationSum2Core(vector<int>& candidates, int target, int index, vector<int>& temp, vector<vector<int>>& res){
        if(target==0&&find(res.begin(),res.end(),temp)==res.end()) {//这里多了一个判断res里是否已经存在temp的步骤，若不存在就添加。
            res.push_back(temp);
            return;
        }
        else if(target<0) return;//一定要返回。
        else{
            for(int i = index; i<candidates.size();++i){
                temp.push_back(candidates[i]);
                combinationSum2Core(candidates, target-candidates[i], i+1, temp, res);
                temp.pop_back();
            }
        }
    }


    // 执行用时 :12 ms, 在所有 C++ 提交中击败了48.23% 的用户
    // 内存消耗 :7.2 MB, 在所有 C++ 提交中击败了100.00%的用户
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if(candidates.size()==0) return res;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());//先对数组排序。
        combinationSum2Core(candidates, target, 0, res, temp);
        return res;
    }
    void combinationSum2Core(vector<int>& candidates, int target, int index, vector<vector<int>> res, vector<int> temp;){
        if(target==0) {//这里多了一个判断res里是否已经存在temp的步骤，若不存在就添加。
            res.push_back(temp);
            return;
        }
        else if(target<0) return;
        else{
            for(int i = index; i<candidates.size();++i){
                if(i!=index&&candidates[i]==candidates[i-1]) continue;//若i不是这一层循环的第一个数，且他等于他之前的那个数。就不用算了。
                temp.push_back(candidates[i]);
                combinationSum2Core(candidates, target-candidates[i], i+1, res, temp);
                temp.pop_back();
            }
        }
    }



    // 执行用时 :4 ms, 在所有 C++ 提交中击败了97.23% 的用户
    // 内存消耗 :7.2 MB, 在所有 C++ 提交中击败了100.00%的用户
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if(candidates.size()==0) return res;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());//先对数组排序。
        combinationSum2Core(candidates, target, 0, temp, res);
        return res;
    }
    void combinationSum2Core(vector<int>& candidates, int target, int index, vector<int>& temp, vector<vector<int>>& res){
        if(target==0) {//这里多了一个判断res里是否已经存在temp的步骤，若不存在就添加。
            res.push_back(temp);
            return;
        }
        else{
            while(index<candidates.size()&&candidates[index]<=target){//使用了while+candidates[index]<=target就不用了写target<0的情况了。
                temp.push_back(candidates[index]);
                combinationSum2Core(candidates, target-candidates[index++], index, temp, res);//这里的index++用的特别巧妙。直接为下面的index加1 
                // combinationSum2Core(candidates, target-candidates[index], ++index, temp, res);//执行用时 :8 ms, 在所有 C++ 提交中击败了82.77% 的用户,++i没有i++快。
                while(index<candidates.size()&&candidates[index]==candidates[index-1]) ++index;//这里因为前面index++所以和index-1比较。若值相等则index++；
                temp.pop_back();
            }
        }
    }


};
```