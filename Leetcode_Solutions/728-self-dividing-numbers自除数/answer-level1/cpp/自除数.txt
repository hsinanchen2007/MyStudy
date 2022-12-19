### 解题思路


### 代码

```cpp
class Solution {
public:
    vector<int> selfDividingNumbers(int l, int r) {
        vector<int> res;
        int tmp,j;
        for(int i = l;i <= r;i++){
            j = i;
            bool flag = true;
            while(j){
                tmp = j % 10;
                if(tmp == 0 || i % tmp != 0) {
                    flag = false;
                    break;
                }
                j /= 10;
            }
            if(flag)
                res.push_back(i);
        }
        return res;
    }
};
```