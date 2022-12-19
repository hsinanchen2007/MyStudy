### 解题思路
本来是想用回溯算法解决的， 也是第一个想法，但是超时了。

改用分治算法，分别计算首位字母。

### 代码

```cpp
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> arr;
        for (int i = 1; i <= n; i++) {
            arr.push_back(i);
        }
        string path;
        while (k > 1) {
            int index = (k - 1) / fac(n - 1);
            int num = arr[index];
            path += to_string(num);
            arr.erase(arr.begin() + index);
            k -= index * fac(n - 1);
            n--;
        }
        while(!arr.empty()) {
            path += to_string(arr[0]);
            arr.erase(arr.begin());
        }
        return path;
    }

private:
    int fac(int n) {
        if (n == 1 || n == 0) {
            return 1;
        } else {
            return n * fac(n - 1);
        }
    }
};
```