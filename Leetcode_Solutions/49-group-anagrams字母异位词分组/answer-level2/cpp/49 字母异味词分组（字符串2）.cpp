```
class Solution {
public:

    //总体方法是：排序+哈希(哈希的方法有很多种，有各个字符相加的和相等很多很多，只要和顺序没关系就行)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //思路：为什么能分到同一类，就是发现将同一类字符串排序的结果都一样,也就是说通过排序后的结果分组
        //用哈希表存放排序结果相等的字符串

        unordered_map<string,vector<string>> hash;//定义一个哈希表
        for(auto str:strs)//遍历字符串
        {
            string k=str;
            sort(k.begin(),k.end());
            hash[k].push_back(str);//将排序相等的key值插入到hash表中
        }
        vector<vector<string>> result;
        for(auto str:hash)
        {
            result.push_back(str.second);
        }
        return result;
    }
};
```
