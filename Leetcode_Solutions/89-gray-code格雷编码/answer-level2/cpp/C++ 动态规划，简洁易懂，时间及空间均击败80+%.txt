由n位推导n+1位结果时，n+1位结果包含n位结果，同时包含n位结果中在高位再增加一个位1所形成的令一半结果，但是这一半结果需要与前一半结果镜像排列
```
    vector<int> grayCode(int n) {
        vector<int> result(1);
        result[0] = 0;
        for(int i = 1; i <= n; i++){
            int e = 1 << (i - 1);                           //i - 1位结果前增加一位1
            for(int j = result.size() - 1; j >= 0; j--){    // 镜像排列
                result.push_back(e + result[j]);
            }
        }
        return result;
    }
```
