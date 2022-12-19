
方法1:排序，然后比较是否相同

方法2: 利用自带的无序map，先统计第一个字符串中的字符数目，然后遍历第二个字符串，遇到相同字符串时，在原来的基础上减去1，如果字符串相同，那么最终都会是0；

方法3:因为题目只用了小写的ASCII字符，那么直接用数组就行了，哈希函数为 f(x) = x - 'a'。


方法1: 基于排序, 36ms

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {

        sort(s.begin(), s.end()); //排序s
        sort(t.begin(), t.end()); //排序t

        return s.compare(t) == 0; //如果完全相同，返回0
        
    }
};
```

方法2: 使用内置的unordered_map, 16ms

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hash_table;
        for (int i = 0; i < s.size(); i++){
            hash_table[s[i]] += 1;
        }
        for (int i = 0; i < t.size(); i++){
            hash_table[t[i]] -= 1;
        }
        //遍历哈希表
        for(auto it = hash_table.begin(); it != hash_table.end(); ++it){
            if (it->second != 0 ) return false;
        }
        return true;
    
        
    }
};
```

方法3: 根据map原理，利用数组实现, 12ms

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        char mytable[26] = {0};
        for ( int i = 0; i < s.size(); i++){
            mytable[ s[i] - 'a' ] += 1;
        }
        for ( int i = 0;i < t.size(); i++){
            mytable[ t[i] - 'a' ] -= 1;
        }
        for ( int i = 0; i< 26; i++){
            if (mytable[i] != 0) return false;
        }
        return true;
        
    }
};
```