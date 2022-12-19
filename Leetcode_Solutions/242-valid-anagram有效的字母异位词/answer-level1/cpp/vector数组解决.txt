### 解题思路
首先判断s,t的长度是否相等；
1.声明vector数组代表26个小写字母，
2.同时遍历s,t字符串，对于s中的每一个字符，在数组对应位置+1；对于t中的每一个字符，在数组对应位置-1
3.遍历完成后，在对数组进行遍历，如果所有元素都为0，则代表s，t是字母异位词。反之不是。
### 代码

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        int n = s.length();
        vector<int> res1(26,0);
        for(size_t i = 0;i< n;++i){
            int temp1 = s[i] - 'a';
            int temp2 = t[i] - 'a';
            res1[temp1] += 1;
            res1[temp2] -= 1;
        }
        for(size_t j = 0;j<res1.size();++j){
            if(res1[j]==0){
                continue;
            }else{
                return false;
            }
        }
        return true;
    }
};
```