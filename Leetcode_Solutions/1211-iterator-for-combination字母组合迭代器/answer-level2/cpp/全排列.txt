求全排列并存储，每次 next() 以后删除一个元素。

```
class CombinationIterator {
   public:
    CombinationIterator(string characters, int combinationLength) {
        dfs(characters, combinationLength, 0, "");
        reverse(paths.begin(), paths.end());
    }

    void dfs(string str, int len, int index, string path) {
        if (path.size() == len) {
            paths.push_back(path);
            return;
        }

        for (int i = index; i < str.size(); i++) {
            dfs(str, len, i + 1, path + str[i]);
        }
    }

    string next() {
        string str = paths[paths.size() - 1];
        paths.pop_back();
        return str;
    }

    bool hasNext() { return paths.size() > 0; }

   private:
    vector<string> paths;
};
```

![image.png](https://pic.leetcode-cn.com/eb84a2203e38f204a16ec9ae5f8148f0582f4271e0d3fb13d7803b7f9807e193-image.png)
