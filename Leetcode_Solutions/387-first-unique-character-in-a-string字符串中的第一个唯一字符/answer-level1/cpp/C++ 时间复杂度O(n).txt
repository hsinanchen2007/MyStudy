1. 遍历两次字符串
2. 第一次统计每个字符出现的次数，用一个大小为26的vector存储结果，vector的下表用字符-'a'计算，正好是0-26；
3. 第二次遍历字符串，如果对应元素出现的次数是1，就返回元素位置
4. 对vector的访问时间复杂度是O(1)，时间复杂度都在字符串的循环上，时间复杂度O(n)
```
int firstUniqChar(string s) 
    {
        vector<int> find(26,0);
        for(int i=0;i<s.length();i++)
            find[s[i]-'a'] += 1;
        set<char> single = {};
        for(int i=0;i<s.length();i++)
            if(find[s[i]-'a'] == 1)
                return i;
        return -1;
    }
```
