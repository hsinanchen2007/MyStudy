## 思路
基于STL的sort，自定义排序规则。判断两个数谁在前，可以通过将两个数m和n谁在前，可以通过比较mn和nm哪个大，由于mn和nm长度相同，所以可以直接进行字典序比较。
**注意**：
- 比较函数cmp的需要为static，因为std::sort是属于全局的，无法调用非静态成员函数。而静态成员函数或全局函数是不依赖与具体对象，可以独立访问。
- 处理特殊数组[0,0]，输出为0，而不是00。 

### 代码
```c++
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res;
        sort(nums.begin(), nums.end(), cmp);
        for (int i = 0; i < nums.size(); ++i) {
            res += to_string(nums[i]);
        }
        if (res[0] == '0') {
            res = '0';
        }
        return res;
    }
    
    static bool cmp(const int &a, const int &b) {
        string s1 = to_string(a) + to_string(b);
        string s2 = to_string(b) + to_string(a);
        return s1 > s2;
    }
};
```
