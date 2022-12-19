这个方案我觉得比较好的是这一步。
result[i] = result[i - two_log_vector[two_log_vector.size() - 2]] + 1;
是利用了二进制本身的数学特点来解决的。

```
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1);
        vector<int> two_log_vector;
        two_log_vector.push_back(1);
        result[0] = 0;
        for(int i = 1; i <= num; ++i) {
            if (two_log_vector.back() == i) {
                result[i] = 1;
                two_log_vector.push_back(two_log_vector.back() * 2);
            }
            else if (two_log_vector.back() < i) {
                result[i] = 1;
                result[i] = result[i - two_log_vector.back()] + 1;
            }
            else {
                result[i] = result[i - two_log_vector[two_log_vector.size() - 2]] + 1;
            }
        }
        return result;
    }
};
```

