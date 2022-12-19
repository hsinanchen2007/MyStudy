### 解题思路
此处撰写解题思路

### 代码

```cpp
class WordsFrequency {
public:
    WordsFrequency(vector<string>& book) {
        for (auto word : book) freq[word]++;
    }
    
    int get(string word) {
        return freq[word];
    }

private:
    unordered_map<string, int> freq;
};

/**
 * Your WordsFrequency object will be instantiated and called as such:
 * WordsFrequency* obj = new WordsFrequency(book);
 * int param_1 = obj->get(word);
 */
```