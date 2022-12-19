### 解题思路
用一个数组对应出现的整数，数组值对应整数出现的次数，最后对应k值输出相应的整数即可
### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> mark(10000, 0);
        for(int count = 0; count < arr.size(); count++){
            mark[arr[count]] += 1;
        }
        vector<int> res(k, 0);
        for(int i = 0, j = 0; j < k; i++){
            for(int a = mark[i]; a > 0 && j < k; a--){
                res[j] = i;
                j++;
            }
        }
        return res;
    }
};
```