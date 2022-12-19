```
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>res;
        int temp[36] = {
                        12,23,34,45,56,67,
                        78,89,123,234,345,456,
                        567,678,789,1234,2345,3456,
                        4567,5678,6789,12345,23456,34567,
                        45678,56789,123456,234567,345678,456789,
                        1234567,2345678,3456789,12345678,23456789,123456789
                       };
        for(int i = 0; i < 36; i++){
            if(low <= temp[i] && temp[i] <= high){
                res.push_back(temp[i]);
            }
        }
        return res;
    }
};
```
![1.png](https://pic.leetcode-cn.com/63487b5832c60ac274d9399c5bec57f500e32952d418356c397ad7ec71b6be0f-1.png)
