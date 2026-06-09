1. C++好像没有提供字符串分割的接口，就自己写了一个字符串切割，每次遇到' '时截取字符串存入向量
2. 为了判断是不是符合模式，需要两个条件
3. 第一：pattern中的所有同样字符，必须在str中对应同样的字符串
4. 第二：pattern中的不同字符，必须在str中对应不同字符串
5. 第一个要求用字典实现，每次找到字典中不存在的字符时将它对应的字符串写成键值对，加入字典
6. 第二个要求用集合实现，每当发现新的字符时，在集合中查找它对应的字符串是否已经被录入过，如果被录入过就返回false
7. 最后为了防止比较过程中，pattern和str的长度不同导致溢出，在比较前先判断是否能进行比较
```
bool wordPattern(string pattern, string str) 
    {

        vector<string> Slist = {};
        int loc = 0;
        while(loc < str.size())
        {
            string word = "";
            while(loc < str.size() && str[loc] != ' ')
            {
                word += str[loc];
                loc++;
            }
            loc++;
            Slist.push_back(word);
        }
        if(Slist.size() != pattern.size())
            return false;
        map<char,string> dict = {};
        set<string> already = {};
        for(int i=0;i<pattern.size();i++)
        {
            if(dict.find(pattern[i]) == dict.end())
            {
                dict[pattern[i]] = Slist[i];
                if(already.find(Slist[i]) != already.end())
                    return false;
                already.insert(Slist[i]);
            }
            else if(dict[pattern[i]] != Slist[i])
                return false;
        }
        return true;
    }
```
