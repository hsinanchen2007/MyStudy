### 1. 子集树解法
虽然是排列树问题，当然也可以用子集树的办法来做。习惯了。。不太习惯排列树的交换方法。

### 代码

```cpp
class Solution {
private:
    vector<vector<int>> res;
    vector<int> x;
    vector<int> nums;

public:
    vector<vector<int>> permute(vector<int>& nums) {
        this->nums = nums;
        dfs(0);
        return res;
    }
    void dfs(int k){ // 决定第k个数选择几
        if(k == nums.size()){
            res.push_back(x);
            return ;
        }
        for(int i=0;i<nums.size(); i++){
            x.push_back(nums[i]);
            if(placeTest(k)){
                dfs(k+1);
            }
            x.pop_back();
        }
    }
    bool placeTest(int k){
        for(int i=0; i<k; i++){
            if(x[i] == x[k]) return false;
        }
        return true;
    }
};
```

### 2. 排列树解法
关键是顺序交换，有两个作用：
- 给当前位置放置一个数
- 将原先位置的数放到后面，不会覆盖。
如果只看最外层的递归，可以发现**每一次迭代的时候面临的都是原先的数组。**
也就是说第一个数和第一个数交换，相当于第一个位置取第一个数，然后让后面的数全排列。
第二轮迭代的时候，我让第一个数和第二个数交换，也就是说让第一个位置取第二个数，然后让其余的数全排列。
第三轮迭代的时候，我让第一个数和第三个数交换，也就是说让第一个位置取第三个数，然后让其余的数全排列。
。。。
第n轮迭代的时候，我让第一个数和第n个数交换，也就是说让第一个位置去第n个数，然后让其余的数全排列。
总共也就这么多情况。换句话说，我们是将所有的排列按照第一个数的取值进行分类，一共有n类。

再回答一个问题： **为什么for循环中的i是从t开始的，而不是从0开始的？**
- 首先从t开始是排列树区别于子集树的重要特征。
- 而排列树为什么要从t开始？因为排列树的函数意义是：决定第t个位置取几。而前面说过，每次迭代之前，面临的数组都是原先的数组，所以显然原先的数组去过的数字已经不能取了，而只能取后面的数字，并且一定要取后面的数字，这也是用交换的原因。

### 代码
```
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums,res,0);
        return res;
    }
    void backtrack(vector<int> & nums, vector<vector<int>> &res, int i){
        if(i == nums.size()){
            res.push_back(nums);
            return ;
        }
        for(int j=i; j<nums.size(); j++){
            swap(nums[i],nums[j]);//当自己和自己换的时候，就表示取原数组的第一个数，
            // 当自己和第二个数交换的时候，就表示取原数组的第二个数
            // 当自己和第3个数的交换的时候，就表示取原数组的第三个数。
            // 其实这才是排列树的一般框架，通过交换来实现取一个数，同时然后让其他的数形成全排列。
            backtrack(nums,res,i+1);
            swap(nums[i],nums[j]);
        }
    }
};
```
