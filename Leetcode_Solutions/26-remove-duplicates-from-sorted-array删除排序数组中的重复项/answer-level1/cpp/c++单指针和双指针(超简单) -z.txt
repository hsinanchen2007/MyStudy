### 解题思路1
遍历nums中的元素n，与指针对应的元素进行比较，如果不同，则替换初始指针后面的位置为新的元素n

![12.png](https://pic.leetcode-cn.com/3293da45d541f50bbc1ef92fb0fbb408197f1f312d4408713e5148323fee31b0-12.png)




    

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size()==0)    return 0;

        int i=0;   //i做指针，记录需要替换元素的位置 
        for(int n:nums)
        {
            if(n!=nums[i])
            nums[++i]=n;
        }

        return i+1;
    }
};
```

### 解题思路2   双指针法    代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size()==0)    return 0;

        int i=0;  //i做指针，记录需要替换元素的位置 
        for(int k=1;k<nums.size();k++)
        {
            if(nums[k]!=nums[i])
            nums[++i]=nums[k];
        }

        return i+1;
    }
};
```