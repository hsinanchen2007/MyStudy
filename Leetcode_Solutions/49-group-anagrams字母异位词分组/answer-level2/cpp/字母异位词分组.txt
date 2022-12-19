### 算法分析
1. 定义哈希表存储排序字符串和对应的字符串数组的下标
2. 遍历strs，对字符串排序，判断排序后的字符串是否存在于哈希表
3. 如果存在则将字符串加入对应下标的字符串数组
4. 否则新建一个字符串数组并将字符串加入该数组，将排序字符串和字符串数组的下标插入哈希表
5. 最后返回result
### 复杂度分析
+ 时间复杂度：O(n)，n字符串数组长度
+ 空间复杂度：O(n)，哈希表占用额外空间
### 源码
```C++ []
class Solution {
public:
    string Hash(string str)
    {
        sort(str.begin(), str.end());
        return str;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, int> hashMap;

        for (auto &&str : strs)
        {
            string hashStr = Hash(str);
            if (hashMap.count(hashStr))
            {
                result[hashMap[hashStr]].push_back(str);
            }
            else
            {
                vector<string> vec;
                vec.push_back(str);
                result.push_back(vec);
                
                hashMap.insert(make_pair(hashStr, result.size() - 1));
            }
        }

        return result;
    }
};