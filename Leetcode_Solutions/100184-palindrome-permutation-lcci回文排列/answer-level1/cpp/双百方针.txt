### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<int,int> m;
        for(int i:s){
            m[i]++;
        }
        
        int odd=0;
        unordered_map<int,int>::iterator iter;
        for(iter=m.begin();iter!=m.end();iter++){
            if(iter->second%2==1) ++odd;//统计出现奇数次的元素
        }
        return odd <= 1;//若出现奇数次的元素个数小于等于1返回true
    }
};
```