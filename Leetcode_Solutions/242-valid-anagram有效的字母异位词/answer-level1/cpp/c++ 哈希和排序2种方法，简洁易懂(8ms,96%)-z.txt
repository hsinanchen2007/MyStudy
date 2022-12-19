### 1.构造哈希
构建哈希数组，索引0-25分别对应26个字母，分别遍历s和t两个string，第一轮对应字母出现一次++，第二轮出现一次--，两个数组如果完全相等，则哈希数组中所有元素的值应为0，

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
            
        int hash[26]={0};       //构建哈希数组
        for(auto n:s)
            hash[n-'a']++;
        for(auto n:t)
            hash[n-'a']--;
        for(int i=0;i<26;i++)
            if(hash[i]!=0)   return false;          //如果两数组不完全相等
        return true;
    }
};
```

### 2.排序
对s和t进行排序，若字母数量一样，排序后结果应该一样
ps:速度差点

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
        return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        return s==t;
    }
};
```

