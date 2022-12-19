### 解题思路
解题: 
(1) 主要 设 nums1中选s个最大序列数，nums2中就是k-s个。进行遍历比较就行
(2) 注意s和k-s的限制条件。注意归并比较技巧 lexicographical_compare
(3) 需要熟写 数组中去k个最大序列数
### 代码

```cpp
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> result;
        int m = nums1.size(), n = nums2.size();
        
        // 设s为nums1选取的个数
        for (int s = max(0, k-n)/*nums1中选取最少的个数*/; s <= min(k, m); s++) {
            vector<int> item;
            vector<int> item1 = max_order_number(nums1, s); // nums1中选取s个表示最大数
            vector<int> item2 = max_order_number(nums2, k-s); // nums2...

            // 归并出最大数
            auto iter1 = item1.begin();
            auto iter2 = item2.begin();
            while (iter1 != item1.end() || iter2 != item2.end()) {
                item.push_back(lexicographical_compare(iter1, item1.end(), iter2, item2.end()) ? *iter2++ : *iter1++);
            }
            result  = lexicographical_compare(item.begin(), item.end(), result.begin(), result.end()) ? result : item;

        }
        return result;
    }

    // 取出 k个最大的序列数
    vector<int> max_order_number(vector<int>& v, int k) {
        int n = v.size();
        if (n <= k)
            return v;
        vector<int> result;
        int pop = n - k; // 表示可以切换的数字个数,如: [5, 4, 3, 7, 8], 在7的时候[5,4,3]把3,4分别弹出，此时pop=0
        for (int i = 0; i < n; i++) {
            while (!result.empty() && v[i] > result.back() && pop-- > 0)
                result.pop_back();
            result.push_back(v[i]);
        }
        result.resize(k); // 这里一定要裁剪，不然长度可能会超过
        return result;
    }
};
```