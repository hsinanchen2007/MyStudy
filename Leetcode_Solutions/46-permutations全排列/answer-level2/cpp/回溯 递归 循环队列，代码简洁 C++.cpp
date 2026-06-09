典型回溯算法题，但是首先要想到怎样回溯，基本思想如下：
    1.固定一个数字（原数组中的索引），选择此数字的存放位置，开头的数字然后处理省下数组中数的存放位置（递归）
    2.下次递归时数组中数据个数应该排除当前递归的数字，而下次递归结束时当前数组中应该包括当前处理的数字（回溯）
    3.下次递归时省下的数组中数据位置应该保持原样（循环队列）
    4.循环1 2两步，每次循环时改变当前固定数字的存放位置
```
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> dst(nums.size());
        queue<int> q;
        for(int i = 0; i < nums.size(); i++){
            q.push(i);
        }
        traverse(nums, dst, q, 0);
        return result;
    }
    
    void traverse(vector<int>& src, vector<int>& dst, queue<int>& q, int src_index){
        if(q.empty()){
            result.push_back(dst);
            return;
        }
        int dst_index;
        for(int i = 0; i < q.size(); i++){
            dst_index = q.front();
            q.pop();
            dst[dst_index] = src[src_index];
            traverse(src, dst, q, src_index + 1);
            q.push(dst_index);
        }
    }
};
```

