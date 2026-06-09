
em，这题开始还在想什么循环数组，然后就开始比划，发现，咦？这不就是整段换位吗，那不就直接成了 
ABC DEF——>DEF ABC
那就直接先各自反转
(ABC---reverse--->CBA) + (DEF---reverse--->FED) = CBA FED ----->然后整个反转 DEF ABC 
OK结束, 遗憾的是不能用系统的reverse函数，于是手写一个呗也不难，中间还是wa了一次，发现k可能大于nums.size()啊，好吧那就取个余
```
class Solution {
public:
    void myreverse(vector<int>& nums, int i, int j)
    {
        while(i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        myreverse(nums, 0, nums.size()-k-1);
        myreverse(nums, nums.size()-k, nums.size()-1);
        myreverse(nums, 0, nums.size()-1);
    }
};
```

