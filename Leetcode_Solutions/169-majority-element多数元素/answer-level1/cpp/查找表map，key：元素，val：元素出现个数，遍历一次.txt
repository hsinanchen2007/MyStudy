这才是对于菜鸡来说的『简单』等级嘛/允悲/允悲
```
    int majorityElement(vector<int>& nums) {
        int times = floor(nums.size() / 2);
        unordered_map<int,int> record;

        for(int i = 0; i <= nums.size(); i++){
            record[nums[i]] ++;
            if(record[nums[i]] > times){
                return nums[i];
            }
        }
        return NULL;
    }
```

不加
```
return NULL;
```
测试用例都过不了

如有问题请指点，大佬求轻喷。
