### 解题思路
此处撰写解题思路

### 代码

```cpp
class WordsFrequency {
private:
    unordered_map<string,int> dic;
public:
    WordsFrequency(vector<string>& book) {
        for(auto a:book)
        {
            dic[a]++;
        }
    }
    
    int get(string word) {
        return dic[word];
    }
};

/**
 * Your WordsFrequency object will be instantiated and called as such:
 * WordsFrequency* obj = new WordsFrequency(book);
 * int param_1 = obj->get(word);
 */
```