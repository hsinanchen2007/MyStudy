0ms可还行！应该有问题吧，望指教
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗 :9 MB, 在所有 C++ 提交中击败了5.29%的用户
### 解题思路
1.sort排序
2.遍历找出与val相等的多少个，n个
3.找到第一个val，erase它和它后面的共n-1个内容，return
### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 排序
        sort(nums.begin(),nums.end());
        // 计算重复个数
        int n=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==val) n+=1;
        }
        if(!n) return nums.size(); //没有相同的就直接返回
        // 删除重复内容
        vector<int>::iterator x = find(nums.begin(),nums.end(),val);//不包括nums.end()
        nums.erase(x,x+n);
        // for循环一样
        // for(int i=0;i<nums.size();++i){
        //     if(nums[i]==val){
        //         nums.erase(nums.begin()+i,nums.begin()+i+n);
        //         break;
        //     }
        // }
        return nums.size();
    }
};
```