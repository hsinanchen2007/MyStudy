* 回溯添加法
    ```
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> track;
        vector<bool> visited(nums.size()); // 记录是否访问
        permute(nums,track,res,visited);
        return res;    
    }
    void permute(const vector<int>& nums,vector<int>& track,vector<vector<int>>& res,vector<bool>& visited){
        if(nums.size() == track.size()){
            res.push_back(track);
            return;
        }
        for(int i=0;i<nums.size();++i){
            if(visited[i]) continue;
            visited[i] = true; // 设置已访问
            track.push_back(nums[i]);
            permute(nums,track,res,visited);
            track.pop_back();
            visited[i] = false; // 恢复已访问
        }
    }
    ```
	
* 回溯添加法--优化(track判断是已存在否存在)
    ```
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> track;
        permute(nums,track,res);
        return res;    
    }
    void permute(const vector<int>& nums,vector<int>& track,vector<vector<int>>& res){
        if(nums.size() == track.size()){
            res.push_back(track);
            return;
        }
        for(auto n:nums){
            if(count(track.begin(),track.end(),n)!=0) continue;// 剪枝
            track.push_back(n);
            permute(nums,track,res);
            track.pop_back();
        }
    }
	```
![](https://pic.leetcode-cn.com/1ff07d3e625bd8acb39d82bf8cfc3a19069510c3316db5f264d9e3cc91c9f472-image.png)

* 回溯交换法
    ```
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permute(nums,0,res);
        return res;    
    }
    void permute(vector<int>& nums,int start,vector<vector<int>>& res){
        if(start == nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=start;i<nums.size();++i){
            swap(nums[i],nums[start]); // 交换位置
            permute(nums,start+1,res);
            swap(nums[i],nums[start]); // 恢复位置
        }
    }
    ```
* 插入法
    ```
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty()) return {{}};
        int front = nums.front(); // 取出第一个元素
        nums.erase(nums.begin());

        // 剩余元素排列
        vector<vector<int>> vecs = permute(nums);

        // 把取出的元素插入所有可能的位置
        for(auto& vec: vecs){
            for(int i=0;i<=vec.size();++i){
                vec.insert(vec.begin()+i,front);
                res.emplace_back(vec);
                vec.erase(vec.begin()+i);
            }
        }
        return res;
    }
    ```
* STL
    ```
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        do{
            res.emplace_back(nums);
        }while(next_permutation(nums.begin(),nums.end()));
        return res;
    }
    ```