## 问题描述
给定一个字符串S，检查是否能重新排布其中的字母，使得两相邻的字符不同。

若可行，输出任意可行的结果。若不可行，返回空字符串。

![](https://pic.leetcode-cn.com/ec43cd2bb4806c832f4cfdaaeaa90c8cec3f75b0be2c406592b64aeaeac81061.png)

[重构字符串](https://leetcode-cn.com/problems/reorganize-string/ "重构字符串")

## 解决方法
### 插空

- 用字典将个字符出现的情况记录下来

- 将字典按照值大小从大到小排序，组成新的字符串t，例如`"aba"`,先排序为`"aab"`

- 取t的左半部分left，隔一插一到S中：`a_a`

- 取t的右半部分right，隔一插一到S中：`aba`

**注意**:如果`left[0]==right[0]`说明不能满足题目要求

```cpp
class Solution {
public:
    static bool cmp_by_val(pair<char,int>& l,pair<char,int>& r){
        return l.second>r.second;
    }
    string reorganizeString(string S) {
        int size=S.size();
        unordered_map<char,int>m;
        for(auto i:S){
            m[i]++;
        }
        vector<pair<char,int>>v(m.begin(),m.end());
        sort(v.begin(),v.end(),cmp_by_val);
        string temp;
        for(auto item:v){
            for(int i=0;i<item.second;i++){
                temp+=item.first;
            }
        }
        string left=temp.substr(0,size&1?size/2+1:size/2);
        string right=temp.substr(size&1?size/2+1:size/2);
        if(left[0]==right[0])return "";
        for(int i=0;i<size;i+=2){
            S[i]=left[i/2];
        }
        for(int i=1;i<size;i+=2){
            S[i]=right[i/2];
        }
        return S;
    }
};
```

my site: [https://liyiping.cn](https://liyiping.cn)