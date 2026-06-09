### 解题思路
首先把数字全部转化为string类型，
然后利用sort函数给此数组排序，
在比较时，若两字符串长度相同，则直接比较，
若长度不同，则两个字符串全都通过重复叠加，
增至两者长度的最小公倍数，然后再比较。

### 代码

```cpp
class Solution {
public:
    static bool cmp(string a,string b){
        string t=a;
        while(t.size()%b.size()!=0){
            t+=a;
        }
        string s=b;
        while(s.size()<t.size()){
            s+=b;
        }
        return t<s;
    }
    string minNumber(vector<int>& nums) {
         vector<string> ans;
         for(int i=0;i<nums.size();i++){
             ans.push_back(to_string(nums[i]));
         }
         sort(ans.begin(),ans.end(),cmp);
         string aa;
         for(int i=0;i<ans.size();i++){
             aa+=ans[i];
         }

         return aa;
    }
};
```