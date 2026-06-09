# 思路
    我们可以用map来保存以同母异位词为key，结果数组中的索引为value的键值对<string, int>：
        1.如果结果数组中已经存在字母异位词的子数组，将字符串插入已有子数组即可
        2.结果结果数组中还没有字母异位词的子数组，插入新的子数组
    所以，问题关键就在于如何将字母异位词映射成相同的key，可以考虑：
        1.单个字符值相加求和，bbb == abc, 显然无法做到
        2.将字符串字符排序，adb -> abd，这样则可以满足上面的要求
# 代码
```
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> retVec;
        unordered_map<string, int> uMap; //key是字符排序后的string，int存放在结果数组中的索引
        for(auto ite = strs.begin(); ite != strs.end(); ++ite) {
            string str = *ite;
            sort(str.begin(), str.end());
            auto res = uMap.find(str);
            if(res == uMap.end()) {
                //结果数组中还没有字母异位词的子数组
                retVec.push_back({*ite});
                uMap.insert({str, retVec.size()-1});
            } else {
                //结果数组中已经存在字母异位词的子数组，插入即可
                retVec[res->second].push_back(*ite);
            }
        }
        return retVec;
    }
};
```

# 运行结果
![QQ截图20200105193404.png](https://pic.leetcode-cn.com/74d58e726e8126f9681fb70dd0340a03ee7b12b0238a49ad585b7019a2f738ac-QQ%E6%88%AA%E5%9B%BE20200105193404.png)



