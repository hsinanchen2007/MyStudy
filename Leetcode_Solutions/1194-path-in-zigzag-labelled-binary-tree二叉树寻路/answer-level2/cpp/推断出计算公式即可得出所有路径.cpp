找到计算公式即可得出所有路径

代码块
```vector<int> pathInZigZagTree(int label) {
        vector<int> result;
        auto begin = result.begin();
        while (label)
        {
            begin = result.insert(begin, label);
            label = 2 * (int)pow(2, (int)log2(label) - 1) - (label - pow(2, (int)log2(label)) + 1)/2;
        }
        return result;
    }
