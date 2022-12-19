```
class FileSystem {
public:
    FileSystem() {
        paths["/"] = {};
    }
    
    vector<string> ls(string path) {
        if (files.count(path)) {
            int e = path.find_last_of('/');
            return {path.substr(e + 1)};
        }
        if (path.back() != '/') {
            path.push_back('/');
        }
        if (!sorted[path]) {
            sort(paths[path].begin(), paths[path].end());
            sorted[path] = true;
        }
        return paths[path];
    }
    
    void mkdir(string path) {
        path.push_back('/');
        for (int i = 1, pos = 0; i < path.size(); i = pos + 1) {
            pos = path.find('/', i);
            if (!paths.count(path.substr(0, pos + 1))) {
                paths[path.substr(0, i)].push_back(path.substr(i, pos - i));
                sorted[path.substr(0, i)] = false;
            }
        }
        if (!paths.count(path)) {
            paths[path] = {};
        }
    }
    
    void addContentToFile(string filePath, string content) {
        if (files.count(filePath)) {
            files[filePath] += content;
        } else {
            files[filePath] = content;
            int e = filePath.find_last_of('/');
            for (int i = 1, pos = 0; i < e; i = pos + 1) {
                pos = filePath.find('/', i);
                if (!paths.count(filePath.substr(0, pos + 1))) {
                    paths[filePath.substr(0, i)].push_back(filePath.substr(i, pos - i));
                    sorted[filePath.substr(0, i)] = false;
                }
            }
            paths[filePath.substr(0, e + 1)].push_back(filePath.substr(e + 1));
            sorted[filePath.substr(0, e + 1)] = false;
        }
    }
    
    string readContentFromFile(string filePath) {
        return files[filePath];
    }
    
    unordered_map<string, vector<string>> paths;
    unordered_map<string, bool> sorted;
    unordered_map<string, string> files;
};
```
