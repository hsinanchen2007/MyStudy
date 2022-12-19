![image.png](https://pic.leetcode-cn.com/08ae28fcb922c67d76cecd4c4838dbd08d7f1d9e75e59f7731a301859a9f8414-image.png)

```
static auto pre =[] { std::ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr;}();
class FileSystem {
public:
    FileSystem() = default;
    
    bool createPath(string path, int value) {
        if (path == "/" || path.empty()) {
            return false;
        }
        auto pos = path.rfind("/");
        if (pos == std::string::npos) {
            return false;
        }
        if (pos != 0) {
            auto prefix = path.substr(0, pos);
            if (paths_.find(prefix) == paths_.end()) {
                return false;
            }
        }
        return paths_.emplace(path, value).second;
    }
    
    int get(string path) {
        auto iter = paths_.find(path);
        if (iter == paths_.end()) {
            return -1;
        }
        return iter->second;
    }

private:
    std::map<std::string, int> paths_;
};
```
