```
// 第一种：暴力法 O(n²)太差了
    vector<int> twoSum1(vector<int>& nums, int target) {
        
        vector<int> ve;

        int size = nums.size();
        for (int i = 0; i < size; i ++) {
            int firstVal = nums[i];
            int scondVal = target - nums[i];
            for (int j = i+1; j < size; j++) {
                if (scondVal == nums[j]) {
                    ve.emplace_back(i);
                    ve.emplace_back(j);
                    return ve;
                }
            }
        }

        return {-1,-1};
    }


// 第二种：unordred_map 内部哈希表来实现 查找时间复杂度为O(1)   map:内部红黑表，有序map，对有序很有利
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashMap;

        int size = nums.size();
        for (int i = 0; i < size; i ++) {
            if (hashMap.count(target - nums[i])) return {hashMap[target-nums[i]],i};
            hashMap[nums[i]] = i;
        }
        // {@3 : 0, @2:1}

        return {-1, -1};
    }
```
