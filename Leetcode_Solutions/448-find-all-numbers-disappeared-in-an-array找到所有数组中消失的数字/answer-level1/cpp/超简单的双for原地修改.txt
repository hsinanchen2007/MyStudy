```
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // 递归的去掉每个出现的元素对应下标的值，用0表示
        // 因为元素是从1~n，而下标是从0~n-1，因此要t-1
        // 因为有可能把其他未遍历的元素给覆盖了，因此用t临时保存，然后用while递归覆盖，
        // 直到遇到元素值为0   
        // 这里最多是O(2n)
        for (int i = 0; i < nums.size(); i++) {
            int t = nums[i];
            while (t != 0) {
                int t1 = nums[t - 1];
                nums[t - 1] = 0;
                t = t1;
            }
        }
        // 找出值非0的元素，由于下标是从0~n-1，因此需要i + 1
        // 这里是O(n)
        vector<int> results;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                results.push_back(i + 1);
            }
        }
        return results;
    }
```
