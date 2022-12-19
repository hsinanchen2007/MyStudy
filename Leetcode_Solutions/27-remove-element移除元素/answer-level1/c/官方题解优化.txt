三种方法都是O(n)复杂度，但是细微之处有差异。

解法一：
最直接思路，不详细解释。每个非val元素都需要比较和移动两次操作。
```
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 官方题解1 + C++版本 + 优化部分语句
        int loc = 0;
        for (int i=0; i<nums.size(); ++i)
            if (nums[i] != val)
                nums[loc++] = nums[i];
        return loc;
    }
};
```


解法二：
官方题解2，后面指针j指向val值元素时仍然会被移动到前面，再加上后面额外处理，会再次移动这个元素。
```
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
	      // 官方题解2 + C++版本  + 优化部分语句
        int i = 0, j = nums.size() - 1;
        while (i <= j){
            if (nums[i] == val){
                swap(nums[i], nums[j--]);
            }
            else
                ++i;
        }
        return j+1;
    }
};
```
											
解法三：
针对官方题解的问题，优化掉val值元素反复移动问题，保证每次交换时j指针所指元素非val即可！
```
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
	      // 最终优化代码
        int i = 0, j = nums.size() - 1;
        while (i <= j){
            while (i<=j && nums[j]==val) --j;
            while (i<=j && nums[i]!=val) ++i;
            if (i > j) break;
            
            swap(nums[i++], nums[j--]);
        }
        return j+1;
    }
};
```


