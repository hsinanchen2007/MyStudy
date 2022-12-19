### 解题思路
1、首先将字符串排序。
2、i表示当前元素位置。
3、保持当前排列，直接排列下一个位置。
4、i之后的每一个元素j与i交换(j与i位置元素相等或j与前一个位置相等说明重复)，然后排列下一个位置。

### 代码

```cpp
class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> ans;
        if(s.empty())
            return ans;
        sort(s.begin(),s.end());
        mut(0,s,ans);
        return ans;
    }
    void mut(int i,string str,vector<string>& ans){
        if(i==str.size()-1){
            ans.push_back(str);
            return;
        }
        int temp;
        mut(i+1,str,ans);
        for(int j=i+1;j<str.size();++j){
            if(str[j]!=str[j-1] && str[j]!=str[i]){
            //mut(j,str,ans);
            temp=str[i];
            str[i]=str[j];
            str[j]=temp;
            mut(1+i,str,ans);
            }
        }
    }
};
```