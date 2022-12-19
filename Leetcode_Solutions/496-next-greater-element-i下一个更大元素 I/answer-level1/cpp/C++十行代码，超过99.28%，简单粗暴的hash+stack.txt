从nums2的后边开始，每一个值压栈：
到达新的值时候判断栈是否为空，为空则数组后面没有大于当前值的元素，对应-1；否则弹出栈顶元素直到大于当前值或者栈为空。
由于所有值唯一，可以考虑建立nums1的值对应索引的hash表，每次操作nums2时判断当前值是否存在于nums1，存在则更新nums1的值。

最后感觉自己有点标题党了（不过核心代码确实是10行），嘻嘻嘻~。~
```
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> maps;
        stack<int> nums2stack;
        auto kv = maps.end();
        for(int i = 0; i < nums1.size(); i++) maps[nums1[i]] = i;
        for(int i = nums2.size() - 1; i >= 0; i--) {
            while(!nums2stack.empty() && nums2stack.top() < nums2[i]) nums2stack.pop();
            kv = maps.find(nums2[i]);
            if(kv != maps.end()) nums1[kv->second] = nums2stack.empty() ? -1 : nums2stack.top();
            nums2stack.push(nums2[i]);
        }
        return nums1;
    }
};
```

![1576028618(1).png](https://pic.leetcode-cn.com/5b58a863154890bbc6f613968f9b1b84eddbde10c37a4fa25a34dec8111dc74f-1576028618\(1\).png)


