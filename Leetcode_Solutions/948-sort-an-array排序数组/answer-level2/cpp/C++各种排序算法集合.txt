# 高级做法Sort
```
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums;
    }
};
```

# 冒泡排序

对于本题:超出时间限制
```
class Solution {
public:
    // 冒泡 
    vector<int> sortArray(vector<int>& nums) {
        int temp = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i; j < nums.size(); j++){
                if(nums[j] < nums[i]){
                    temp = nums[j];
                    nums[j] = nums[i];
                    nums[i] = temp;
                }
            }
        }
        return nums;
    }
};
```


# 选择排序

对于本题:超出时间限制
```
class Solution {
public:
    // 选择排序
    vector<int> sortArray(vector<int>& nums) {
        int minIndex = 0; // 最小值索引
        int temp = 0; // 交换
        int len = nums.size();
        for(int i = 0; i < len; i++){
            minIndex = i;
            for(int j = i + 1; j < len ; j++){
                if(nums[j] < nums[minIndex]){
                     minIndex = j;
                }
            }    
            temp = nums[minIndex];
            nums[minIndex] = nums[i];
            nums[i] = temp;
        }
        return nums;
    }
};
```
