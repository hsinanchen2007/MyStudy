算法描述如下：
1. nums数组排序
2. 将nums数组转换为存储类型tag的数组s,tag类型包括val和num两个变量，顾名思义，此时数组s中不存在重复变量
3. 回溯（递归），在处理s中每个元素时，需要根据num值生成num个分别包含1-num个val元素的子集
4. 回溯算法本质是递归，递归后不要忘记回退（代码里的pop)

```
class Solution {
public:
    struct tag{
        int val;
        int num;
    };
    void push(vector<int>& inst, vector<tag>& s, int index, int n){
        for(int i = 0; i < n; i++){
            inst.push_back(s[index].val);
        }
    }
    
    void pop(vector<int>& inst, int n){
        for(int i = 0; i < n; i++){
            inst.pop_back();
        }
    }
    void recall(vector<vector<int>>& result, vector<int>& inst, vector<tag>& s, int i, int n){
        if(n == 0){
            result.push_back(inst);
            return;
        }
        for(int j = i; j <= (s.size() - n); j++){
            for(int k = 1; k <= s[j].num; k++){
                push(inst, s, j, k);
                recall(result, inst, s, j + 1, n - 1);
                pop(inst, k);
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<tag> s;
        vector<vector<int>> result;
        if(nums.size() == 0) return result;
        
        for(int i = 0; i < nums.size(); i++){
            if(i == 0 || nums[i] != nums[i - 1]){
                tag t = {nums[i], 1};
                s.push_back(t);
            }else{
                s[s.size() - 1].num += 1;
            }
        }
        
        vector<int> inst;
        for(int n = 1; n <= s.size(); n++){
            recall(result, inst, s, 0, n);
        }
        result.push_back(vector<int>());
        return result;
    }
};
```
