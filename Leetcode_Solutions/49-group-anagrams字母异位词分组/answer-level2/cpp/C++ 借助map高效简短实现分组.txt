### 核心思想
#### 初步思路
字符串数组的初始标签全部设为true。遍历字符串数组，外层i，该数设为false，内层begin=i+1，如果满足判定条件（ bool isAnagram(string s, string t)），置为false，放入和外层相同的数组；外层每一层是一个数组；时间复杂度O（n*n），空间复杂度O（n）
总结：此思路是基础写法，实现起来并不难，效率也不好，因此摒弃，本文的重点是下方运用map的成熟思路

#### 成熟思路（map）
先给字符串数组里的每个字符串s另存为t，进行排序
t作为map的权柄key值，s则插入这个权柄的字符串数组里
再把map的每一项的second项取出来推到ret里

```
vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ret;
        map<string , vector<string> >mp;
        for(auto s : strs )
        {
            string t=s;
            sort(t.begin(),t.end());
            mp[t].push_back(s);
        }
        for(auto x :  mp)
        {
            vector<string>temp(x.second.begin(),x.second.end());
            ret.push_back(temp);
        }
        return ret;
    }
```
