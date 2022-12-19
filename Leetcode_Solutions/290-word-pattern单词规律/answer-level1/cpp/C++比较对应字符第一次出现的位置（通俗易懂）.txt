### 解题思路
因为考虑到str是单词的定位，可能出现前缀字符串，为便于操作特将题目给的str中单词提取到数组中，但数组定位又无法直接调用库函数(如string的find方法)**(或许有，作者出入门未了解)**,因此特地写了个定位函数。

### 代码

```cpp
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        /**
            方法2：找第一次出现的位置——
            时间复杂度:O(n^2)~~~原子操作中函数indexOfStr时间复杂度为O(n)
            空间复杂度:O(n)
        */
        vector<string> arr;
        // 解析字符串str到数组
        stringstream out(str);
        string word;
        while(out>>word) arr.push_back(word);

        if(arr.size() != pattern.size()) return false;

        //找第一次出现的位置
        for(int i=0;i<pattern.size();i++)
        {
            if(pattern.find(pattern[i]) != indexOfStr(arr[i],arr)) return false;
        }
        return true;
    };
    // 求str解析出的arr数组中任意元素第一次出现的位置
    int indexOfStr(string s,vector<string> arr)
    {
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i] == s) return i;
        }
        return 0;
    }
};
```