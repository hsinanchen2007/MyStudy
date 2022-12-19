### 解题思路
我们构建一个map，可以直接搞定

### 代码

```cpp
class WordsFrequency {
public:
    WordsFrequency(vector<string>& book) {
        for(int i=0;i<book.size();i++){
            res[book[i]]++;
        }
    }
    
    int get(string word) {
        map<string,int>::iterator it;
        it = res.find(word);
        if(it != res.end()) return res[word];
        else return 0;
    }
private:
    map<string,int> res;
};

/**
 * Your WordsFrequency object will be instantiated and called as such:
 * WordsFrequency* obj = new WordsFrequency(book);
 * int param_1 = obj->get(word);
 */
```