### 解题思路
哈希表，默认为空间为O(1) 但是最坏情况为O(n)
位运算 参考官方方法

### 代码

```cpp
/* 哈希表，默认为空间为O(1) 但是最坏情况为O(n) */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> res;
        int ans;
        for(auto i : nums){
            if(res.count(i))   res.erase(i);
            else    res.insert(i);
        }
        for(auto j : res)  ans = j;
        return ans;
    }
};


/* 位运算，一开始没看懂 
如果我们对 0 和二进制位做 XOR 运算，得到的仍然是这个二进制位
a \oplus 0 = aa⊕0=a
如果我们对相同的二进制位做 XOR 运算，返回的结果是 0
a \oplus a = 0a⊕a=0
XOR 满足交换律和结合律
a \oplus b \oplus a = (a \oplus a) \oplus b = 0 \oplus b = ba⊕b⊕a=(a⊕a)⊕b=0⊕b=b
所以我们只需要将所有的数进行 XOR 操作，得到那个唯一的数字。
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++){
            res ^= nums[i];
        }
        return res;
    }
};
```