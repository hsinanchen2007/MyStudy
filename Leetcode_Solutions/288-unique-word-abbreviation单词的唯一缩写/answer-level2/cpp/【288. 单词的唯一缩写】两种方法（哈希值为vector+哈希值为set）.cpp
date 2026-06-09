## 思路一：哈希值为vector
唯一两种情况：
- 不在字典中
- 在字典中但为单词本身
### 代码
```c++
class ValidWordAbbr {
    unordered_map<string, vector<string>> umap;
public:
    ValidWordAbbr(vector<string>& dictionary) {
        for (auto d : dictionary) {
            int size = d.size();
            if (size > 2) {
                string str = d[0] + to_string(size - 2) + d[size - 1];                
                umap[str].push_back(d);
            } 
        }
    }
    
    bool isUnique(string word) {
        int size = word.size();
        if (size > 2) {
            string str = word[0] + to_string(size - 2) + word[size - 1];            
            if (umap.count(str) > 0) {
                if (umap[str].size() > 1) return false;
                if (umap[str].size() == 1 && umap[str][0] != word) return false;
            }
        } 
        return true;
    }
};
```

## 思路二：哈希值为set
### 代码
```c++
class ValidWordAbbr {
    unordered_map<string, set<string>> umap;
public:
    ValidWordAbbr(vector<string>& dictionary) {
        for (auto d : dictionary) {
            string str = toAbb(d);                
            umap[str].insert(d);            
        }
    }
    
    bool isUnique(string word) {        
        string str = toAbb(word);
        return umap.count(str) == 0 || (umap[str].size() == 1 && umap[str].count(word) == 1);
    }

    string toAbb(string word) {
        int size = word.size();
        if (size < 3) {
            return word;
        }
        return word[0] + to_string(size - 2) + word[size - 1];
    }
};
```

