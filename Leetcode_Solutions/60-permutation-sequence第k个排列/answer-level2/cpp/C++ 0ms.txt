![Screenshot from 2019-09-14 23-38-52.png](https://pic.leetcode-cn.com/5e041650e17dcd27ae5f6758c49b1f1aefa6015e90001802f972ac8f39eb1924-Screenshot%20from%202019-09-14%2023-38-52.png)


```
class Solution {
public:

    vector<int> table = {
        0,
        1,
        2,
        6,
        24,
        120,
        720,
        5040,
        40320,
        362880,
        3628800
    };

    void getPermutation(int *p, int size, int k){
        if(size <= 1){
            return;
        }
        k %= table[size];
        sort(p, p + size);
        int i = k / table[size - 1];
        if(i != 0){
            swap(p[0], p[i]);
        }
        getPermutation(p + 1, size - 1, k % table[size - 1]);
    }

    string getPermutation(int n, int k) {
        string result;
        int v[n];
        for(int i = 0; i < n; i++){
            v[i] = i + 1;
        }
        getPermutation(v, n, k - 1);
        for(int i = 0; i < n; i++){
            result.append(to_string(v[i]));
        }
        return result;
    }
};
```
