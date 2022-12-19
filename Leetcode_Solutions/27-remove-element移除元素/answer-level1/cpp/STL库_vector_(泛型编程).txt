class Solution
//113/113 cases passed (4 ms)
//Your runtime beats 76.53 % of cpp submissions
//Your memory usage beats 100 % of cpp submissions (6.3 MB)
```
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        auto itor = nums.begin();       //定义一个iterator指针遍历nums
        for (itor = nums.begin(); itor != nums.end(); itor++)
            if (*itor == val)
                itor-- = nums.erase(itor); //因为erase的返回值是下一个元素的地址，因此要先-1
        return nums.size();
    }
};
```
注意vector.erase()的返回值就行，如果多个val值元素连在一起就会跳过一个元素
