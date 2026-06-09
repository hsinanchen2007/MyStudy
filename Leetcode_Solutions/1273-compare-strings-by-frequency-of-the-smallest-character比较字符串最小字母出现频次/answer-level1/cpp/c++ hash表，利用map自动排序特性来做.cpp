### 解题思路
此处撰写解题思路
unordered_map和map类似，都是存储的key-value的值，可以通过key快速索引到value。不同的是unordered_map不会根据key的大小进行排序
所以使用map<char,int>

### 代码

```cpp
class Solution {
public:
    int mintimes(string str){
        map<char,int> hash;
        
        for(int i = 0;i<str.size();i++){
            hash[str[i]]++;
        }
        int res = hash.begin()->second;//map根据key会自动排序，所以最小的就是最开始的
        return res;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> res;
        vector<int> word2(words.size(),0);
        //算出words中的所有单词经过f（）函数之后的值
        for(int i = 0;i<words.size();i++){
            word2[i] = mintimes(words[i]);
        }


        for(int i = 0;i<queries.size();i++){
            int minpos = mintimes(queries[i]);//计算queries中单词经过f（）的值
            int temp = 0;
            for(int j = 0;j<word2.size();j++){
                if(minpos < word2[j]){
                    temp++;
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};
```