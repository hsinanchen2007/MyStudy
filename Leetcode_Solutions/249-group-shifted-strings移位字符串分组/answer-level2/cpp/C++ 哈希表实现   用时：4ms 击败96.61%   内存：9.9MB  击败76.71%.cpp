// 通过使用哈希表，建立字符串与vector对象下标之间的映射，当某一类字符串（将题目中的"abc" -> "bcd" -> ... -> "xyz"视为一类字符串）从未出现过时，将其添加进哈希表中，并创建一个新的vector对象，其下标保存在哈希表中。

// 对于其他属于某一类的字符串，将其与开头为a的字符串对齐，即实现反向移位操作（"bcd"，"xyz"变回"abc"），这里要注意a向左移一位会变成z。

// 重构完字符串后判断其之前是否出现过，如果出现过则加入对应下标的vector对象中。

// ![image.png](https://pic.leetcode-cn.com/90b06b221d5ef617999d6f0a97ec25c52427d22c53df8222c0e054661497d748-image.png)

// 代码：
// ```
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> vec2;
        unordered_map<string, int> hashmap;
        int index = 0;
        
        for (auto key : strings) {
            string ss(key);
            if (ss[0] != 'a') {
                for (int i = 1; i < ss.length(); i++)
                    ss[i] = (ss[i]- ss[0] + 26) % 26 + 'a';
                ss[0] = 'a';
            }
 
            if (hashmap.count(ss) > 0) {
                vec2[hashmap[ss]].push_back(key);
                continue;
            }
            hashmap[ss] = index++;
            vec2.push_back({key});
        }
        
        return vec2;
    }
};
// ```

// **（萌新初学C++，如果有说的不对的地方希望大家可以指正，如果算法能继续优化的话也欢迎讨论😁😁😁）**
