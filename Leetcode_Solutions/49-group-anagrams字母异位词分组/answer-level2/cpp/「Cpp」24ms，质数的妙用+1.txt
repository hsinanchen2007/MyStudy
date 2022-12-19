### 解题思路

按照官方题解，构建出`#1#2..`表征一个字符串的最大问题在于，字符串的哈希函数速度可能会拖累整体效率，也就是O(1)的常数效率未必就真的比排序的O(nlog n)的快。

通过学习优秀经验，学到了**正整数的唯一分解定理**，即：每个大于1的自然数，要么本身就是质数，要么可以写为2个以上的质数的积。也就是利用质数的乘积来替代原来的`#1#2#`的字符串形式。

### 代码

优化前

```cpp
class Solution {
public:
    string encodeStr(string str){
        string res;
        int freq_arr[26] = {0};
        for ( auto ch : str){
            freq_arr[ch - 'a']++;
        }
        for( int i = 0; i < 26; i++){
            res += "#";
            res += to_string(freq_arr[i]);
        }
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> res;
        unordered_map<string, int> word_tbl; //key为字符频数, value为位置
        int index = 0; //数组下标

        string freq_key;

        for (auto str : strs){
            freq_key = encodeStr(str);
            
            if ( word_tbl.count(freq_key) ){
                res[ word_tbl[freq_key] ].push_back(str);
            } else{
                vector<string> vec(1, str);
                res.push_back(vec);
                word_tbl[freq_key] = index++;
            }

        }
        return res;
        
    }
};
```

优化后

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //26个字母的质数对应表
        int char_hash[26] = {
            2,  3,  5,  7,  11, 
            13, 17, 19, 23, 29,
            31, 37, 41, 43, 47, 
            53, 59, 61, 67, 71,
            73, 79, 83, 89, 97, 
            101 
        } ;
        vector<vector<string>> res;
        unordered_map<unsigned long, int> word_table;
        int index = 0; //对应res的二维下标

        for (auto str : strs){
            unsigned long hash_key = 1;
            for (auto ch : str){
                hash_key *= char_hash[ch-'a'];
            }
            if ( word_table.count(hash_key) > 0 ) {
                res[word_table[hash_key]].push_back(str);
            } else{
                vector<string> temp(1, str);
                res.push_back(temp);
                word_table[hash_key] = index++;
            }
        }
        return res;
        
    }
};
```