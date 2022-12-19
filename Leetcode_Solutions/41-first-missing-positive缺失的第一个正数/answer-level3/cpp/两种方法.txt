## 问题描述
给定一个未排序的整数数组，找出其中没有出现的最小的正整数。
![](https://pic.leetcode-cn.com/28a31d0d693b2829ac845ff4b15a06022a1f4b8bcf1116a339dfa34ad00b5883.png)

[缺失的第一个正数](https://leetcode-cn.com/problems/first-missing-positive/ "缺失的第一个正数")

## 解决方法

### 三次遍历


- 第一次遍历将数组中非正数设置为`INT_MAX`(刚开始设置的`0`，`[0,1,2]`用例过不去)

- 第二次遍历将在数组范围内的数字取负

- 第三次遍历找到下标与值不同的索引返回，否则返回数组大小加一

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size=nums.size();
        for(int i=0;i<size;i++){
            if(nums[i]<=0)nums[i]=INT_MAX;
        }

        for(int i=0;i<size;i++){
            if(abs(nums[i])>0 && nums[i]<=size && abs(nums[i])!=INT_MAX){
                nums[abs(nums[i])-1]=0-abs(nums[abs(nums[i])-1]);
            }
        }

        // for(int i=1;i<=size;i++){
        //     cout<<nums[i-1]<<" ";
        // }

        for(int i=1;i<=size;i++){
            if(nums[i-1]>=0)return i;
        }
        return size+1;
    }
};
```

### 鸽巢定理

自己的数占自己的位置，连续交换就完事了。

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size=nums.size();
        for(int i=0;i<size;i++){
            while(nums[i]>0 && nums[i]<=size && nums[i]!=nums[nums[i]-1])swap(nums[i],nums[nums[i]-1]);
        }
        for(int i=1;i<=size;i++){
            if(i!=nums[i-1])return i;
        }
        return size+1;
    }
};
```

个人网站：[https://liyiping.cn](https://liyiping.cn])