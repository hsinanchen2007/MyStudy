其实就是在组合时想个办法不要添加重复子集,如果能够保证由长度为n的子集生成长度n-1的子集是不会出现重复,那就可以保证最后的解集不会出现重复子集。
思路就是每次都添加比当前子集长度小1的子集
例如1234会添加234,134,124,234
而234又会添加23,24,34,但是会发现134也会添加34,是因为都是从1234中去掉1和2,只是去掉的顺序不同,所以这里就可以发生剪植.思路就是这一个子集上一次被去掉的下标开始去掉元素,否则很容易证得会和前面的子集的生成的组合重复,还是看代码方便，c++可以跑到0ms/4ms.
```
class Solution {
public:
    vector<vector<int> > ans;
    vector<int> tmp;
    vector<vector<int>> subsets(vector<int>& nums) {
        f(nums, 0);
        return ans;
    }
    void f(vector<int> nums,int pos)
    {
        ans.push_back(nums);
        int l = nums.size();
        for(int i = pos; i < l; ++i)
        {
            tmp.assign(nums.begin(), nums.end());
            tmp.erase(tmp.begin()+i);
            f(tmp, i);
        }
    }
};
```
