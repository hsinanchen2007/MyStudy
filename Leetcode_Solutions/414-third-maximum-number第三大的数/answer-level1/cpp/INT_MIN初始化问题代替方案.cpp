问题描述：
定义3个变量分别记录前3大的数，不容易初始化。如果初始化为INT_MIN，那么第3个变量如果最终是INT_MIN，则无法判定有没有取到第3大的数。

解决方案：
1、采用表示更大范围的long定义变量，就是要初始化为比所有数据都小且能比较的数。
2、采用3个int指针记录，用指针是否为nullptr判断是否取到第3个数
3、采用vector记录，利用vector.size()大小判定。

方案2代码：
```
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int *max1 = nullptr, *max2 = nullptr, *max3 = nullptr;
        
        for (int i=0; i<nums.size(); ++i){
            if (max1 == nullptr || nums[i] > *max1){
                max3 = max2;
                max2 = max1;
                max1 = &nums[i];
            }
            else if (nums[i] == *max1)
                continue;
            else if (max2 == nullptr || nums[i]>*max2){
                max3 = max2;
                max2 = &nums[i];
            }
            else if (nums[i] == *max2)
                continue;
            else if (max3 == nullptr || nums[i]>*max3)
                max3 = &nums[i];          
        }
        if (max3 == nullptr)
            return *max1;
        return *max3;        
    }
};
```

方案3代码：
```
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<int> res;
        
        for (int i=0; i<nums.size(); ++i){
            if (res.size() < 3 || nums[i]>res[0])
                // 插入元素
                insertVector(res, nums[i]);
            
            if (res.size() > 3)
                // 维持res大小为3
                res.erase(res.begin());
        }
        
        if (res.size() < 3)
            return res[res.size()-1];
        return res[0];
    }
    
    void insertVector(vector<int>& res, int num){
        if (res.size()==0 || num>res[res.size()-1]){
            res.push_back(num);
            return;
        }
        
        for (auto it=res.begin(); it!=res.end(); ++it){
            if (num == *it)
                return;
            
            if (num < *it){
                res.insert(it, num);
                return;
            }
        }
    }
};
```

———————————————————————————————————————————————————————————————————————————————————————————
方案3显然更具有通用性，接下来做姊妹题[leetcode 215](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/),方案3稍加修改就a了。
```
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> res;
        
        for (int i=0; i<nums.size(); ++i){
            if (res.size()<k || nums[i]>res[0])
                insert_vector(res, nums[i]);
            
            if (res.size() > k)
                res.erase(res.begin());            
        }
        return res[0];
    }
    
    void insert_vector(vector<int> &res, int num){
        if (res.size()==0 || num>res[res.size()-1]){
            res.push_back(num);
            return;
        }
        
        for (auto it=res.begin(); it!=res.end(); ++it){
            if (num <= *it){
                res.insert(it, num);
                return;
            }
        }
    }
};
```
