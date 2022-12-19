
```
class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<32> n_index(n);
        string s_index=n_index.to_string();//转换为字符串
        int num=count(s_index.begin(),s_index.end(),'1');//统计字符串中的‘1’的个数
        return num;
    }
};
```
