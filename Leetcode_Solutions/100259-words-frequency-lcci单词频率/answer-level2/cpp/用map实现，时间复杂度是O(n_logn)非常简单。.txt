### 解题思路
直接统计出现的次数，提供后面查询

### 代码

```cpp
class WordsFrequency {
private:
    map<string, int> mBook;
public:
    WordsFrequency(vector<string>& book) {
        // 保存到map中，单词出现的次数作为第二个参数的值，单词本身作为键
        for(int i = 0; i < book.size(); i++) {
            mBook[book[i]]++;
        }
    }
    
    int get(string word) {
        map<string, int>::iterator it;
        // 立马返回结果
        if((it = mBook.find(word)) != mBook.end())
            return it->second;
        return 0;
    }
};

/**
 * Your WordsFrequency object will be instantiated and called as such:
 * WordsFrequency* obj = new WordsFrequency(book);
 * int param_1 = obj->get(word);
 */
```