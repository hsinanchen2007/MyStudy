```
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>res;
        if(n % 2 != 0){
            res.push_back(0);
            n--;
        }
        for(int i = 0; i < n / 2; i++){
            res.push_back(-i-1);
        }
        for(int i = 0; i < n / 2; i++){
            res.push_back(i+1);
        }
        return res;
    }
};
```
![1.png](https://pic.leetcode-cn.com/ad30fe5fd89be492a1238a78a44629d3633c1ff741a591add2db68ce69251d12-1.png)
没错，又找回了点信心:)