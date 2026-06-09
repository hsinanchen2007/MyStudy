### 解题思路
跟内存文件系统那道题类似，用trie记录节点

### 代码

```cpp
class FileSystem {
public:
    FileSystem() {
        root = new trie();
    }
    
    bool createPath(string path, int value) {
        vector<string> pathVec;
        bool rc = getPathVec(path, pathVec);
        if (rc == false) {
            return false;
        }

        string file = pathVec.back();
        pathVec.pop_back();

        trie *cur = root;
        for (auto each : pathVec) {
            if (cur->next.count(each) == 0) {
                return false;
            }
            cur = cur->next[each];
        }

        if (cur->next.count(file) != 0) {
            return false;
        } else {
            cur->next[file] = new trie();
            cur->next[file]->value = value;
        }

        return true;
    }
    
    int get(string path) {
        vector<string> pathVec;
        bool rc = getPathVec(path, pathVec);
        if (rc == false) {
            return -1;
        }

        trie *cur = root;
        for (auto each : pathVec) {
            if (cur->next.count(each) == 0) {
                return -1;
            }
            cur = cur->next[each];
        }

        return cur->value;
    }
private:
    struct trie {
        unordered_map<string, trie*> next;
        int value;
    };

    trie *root;

    bool getPathVec(string path, vector<string>& pathVec) {
        path.erase(0, 1);
        stringstream ss(path);
        string s;

        while (getline(ss, s, '/')) {
            if (s == "" || s.find(" ") != string::npos) {
                return false;
            } else {
                pathVec.push_back(s);
            }
        }

        if (pathVec.empty()) {
            return false;
        } else {
            return true;
        }
    }
};


/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */
```