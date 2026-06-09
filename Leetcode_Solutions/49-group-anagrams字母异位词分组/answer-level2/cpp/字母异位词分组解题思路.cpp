### 解题思路
  本题本质是一个字符串排序的题目，之后的分组可以采用hash表，通过键值对的映射关系，将已经排好序的字符串和之没有排好序的字符串之间建立联系，最后结果用二维数组存储，将hash表中第二个元素即原来未排序的字符串放在一起即为答案。

### 代码

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hash;//创建hash表
        for(auto str : strs)//遍历u所有字符串
        {
            string key = str;
            sort(key.begin(),key.end());
            hash[key].push_back(str);
        }
        vector<vector<string>> res;
        for(auto items : hash)
        {
            res.push_back(items.second);
        }
        return res;
    }
};
```