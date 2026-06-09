对[全排列](https://leetcode-cn.com/problems/permutations/solution/cduo-fang-fa-shi-xian-quan-pai-lie-by-jdzhangxin/)部分修改。

* 回溯添加法(排序剪枝)
    ```
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> track;
        vector<bool> visited(nums.size());
        sort(nums.begin(),nums.end());
        permuteUnique(nums,track,res,visited);
        return res;    
    }
    void permuteUnique(const vector<int>& nums,vector<int>& track,vector<vector<int>>& res,vector<bool>& visited){
        if(nums.size() == track.size()){
            res.push_back(track);
            return;
        }
        for(int i=0;i<nums.size();++i){
            if(visited[i]) continue;
            if(i>0 && !visited[i-1] && nums[i-1] == nums[i]) continue; // 与前一个节点相等，并且前一个节点未访问
            visited[i] = true; // 设置已访问
            track.push_back(nums[i]);
            permuteUnique(nums,track,res,visited);
            track.pop_back();
            visited[i] = false; // 恢复已访问
        }
    }
    ```
![](https://pic.leetcode-cn.com/12b285120fc4ea3c4545f8a945fb7c85112551ba4273da9d09d6f176dd598b7d-image.png)

* 回溯添加法(set去重)
    ```
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> track;
        vector<bool> visited(nums.size());
        permuteUnique(nums,track,res,visited);
        return {res.begin(),res.end()};    
    }
    void permuteUnique(const vector<int>& nums,vector<int>& track,set<vector<int>>& res,vector<bool>& visited){
        if(nums.size() == track.size()){
            res.insert(track);
            return;
        }
        for(int i=0;i<nums.size();++i){
            if(visited[i]) continue;
            visited[i] = true; // 设置已访问
            track.push_back(nums[i]);
            permuteUnique(nums,track,res,visited);
            track.pop_back();
            visited[i] = false; // 恢复已访问
        }
    }
	```
![](https://pic.leetcode-cn.com/62a2a28dbc3d7574a5287324c307d1b46cf249098528beba51bd7b25abaf42bf-image.png)

* 回溯交换法(set去重)
    ```
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        permuteUnique(nums,0,res);
        return {res.begin(),res.end()};    
    }
    void permuteUnique(vector<int>& nums,int start,set<vector<int>>& res){
        if(start == nums.size()){
            res.insert(nums);
            return;
        }
        for(int i=start;i<nums.size();++i){
            swap(nums[i],nums[start]); // 交换位置
            permuteUnique(nums,start+1,res);
            swap(nums[i],nums[start]); // 恢复位置
        }
    }
    ```
![](https://pic.leetcode-cn.com/307227b82cc19d74dbfc7daecaa08b7891f884df2ac882df665300f2a541075a-image.png)

* 插入法(set去重)
    ```
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res = permute(nums);
        return {res.begin(),res.end()};
    }
    set<vector<int>> permute(vector<int> &nums) {
        set<vector<int>> res;
        if(nums.empty()) return {{}}; // 
        int front = nums.front(); // 取出第一个元素
        nums.erase(nums.begin());
        // 剩余元素排列
        set<vector<int>> vecs = permute(nums);

        // 把取出的元素插入所有可能的位置
        for(auto vec: vecs){
            for(int i=0;i<=vec.size();++i){
                vec.insert(vec.begin()+i,front);
                res.insert(vec);
                vec.erase(vec.begin()+i);
            }
        }
        return res;
    }
    ```
![](https://pic.leetcode-cn.com/853e942d6e8704332d420c87ccb45965b03072b8cf46fc2bfa69d2281a4c1de9-image.png)
