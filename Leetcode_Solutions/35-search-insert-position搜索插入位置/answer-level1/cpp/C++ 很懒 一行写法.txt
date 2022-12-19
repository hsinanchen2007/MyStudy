就是用lower_bound()
有类似
```
int vector<T>::lower_bound(T target,int begin=0,int end=vector<T>::size());
```
的函数就更好了
代码如下，如果有更懒更短的写法请dalao(s)不要私藏：
```
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(),nums.end(),target)-nums.begin();
    }
};
```
