### 解题思路
```cpp
执行用时 :4 ms, 在所有 C++ 提交中击败了99.05%
的用户内存消耗 :12.9 MB, 在所有 C++ 提交中击败了100.00%的用户
```
这里我们需要定义一种排序规则，假设对于两个数m和n，如果mn<nm，那么我们认为m小于n，相反如果nm<mn，那么我们认为n<m。

同时，考虑到直接把数字拼接起来，很有可能会造成溢出int类型，因此我们应该将所有的数字转换成字符串，并且使用上面定义的

规则进行排序。排序之后，将所有字符串拼接起来就可以得到结果。

### 代码

```cpp
bool compare(const string& str1,const string& str2){
    string combine1=str1+str2;
    string combine2=str2+str1;
    return combine1<combine2;
}
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strNums;
        for(int i=0;i<nums.size();++i){
            strNums.push_back(to_string(nums[i]));
        }
        sort(strNums.begin(),strNums.end(),compare);
        string res="";
        for(auto str:strNums) res+=str;
        return res;
    }
};
```