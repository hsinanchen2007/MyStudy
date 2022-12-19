### 0. 思路

题目很简单，也容易懂，这里简单说一下思路：
+ 首先在数组`nums`中找到最大值`max`或者它的索引`index`，并以`max`构造根节点`root`；
+ `root->left`: 接着对`index`左端的部分数组找最大值，并构造节点
+ `root->right`: 接着对`index`右端的部分数组找最大值，并构造节点
+ 后面的工作交给递归就可以了~~

需要注意的就是递归结束的条件，仔细想想是什么吧~

### 1. 自己找最大值

所以需要写一个找最大值及其索引的方法`searchMax`，我一般喜欢**左闭右闭区间**做处理。

**代码：**

```cpp
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }

    TreeNode* helper(vector<int>& nums, int start, int end){
        // 递归结束
        if(start > end) return nullptr;
        // 找到最大值以及索引
        int index = searchMax(nums, start, end);
        // 构造根节点
        TreeNode* root = new TreeNode(nums[index]);
        root->left = helper(nums, start, index-1); 
        root->right = helper(nums, index+1, end);
        return root;
    }

    /*
    * nums：  数组
    * start： 数组起始查找位置(闭区间)
    * end：   数组结束查找位置(闭区间)
    * return：起始到结束区间内，最大值索引
    */
    int searchMax(vector<int>& nums, int start, int end){
        int maxValue = nums[start], index = start;
        for(int i = start+1; i<=end; ++i){
            if(maxValue < nums[i]){
                maxValue = nums[i];
                index = i;
            }
        }
        return index;
    }
};
```

### 2. 使用标准库函数 std::max_element

库函数`std::max_element`可以在一个迭代区间内查找最大值，并返回其迭代器；

需要注意的是，标准库的区间一般都是**左闭右开**的。

**代码：**

```cpp
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums.begin(), nums.end());
    }
private:
    TreeNode* helper(vector<int>::iterator start, vector<int>::iterator end){
        if(start == end) return nullptr;
        auto it = max_element(start, end);
        TreeNode* root = new TreeNode(*it);
        root->left = helper(start, it);
        root->right = helper(it + 1, end);
        return root;
    }
};
```