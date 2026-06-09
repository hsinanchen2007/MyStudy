循环遍历，按照定义判定，某一位为0或无法自除则break判定下一个数

代码：
```
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i <= right; i++) {
            int temp = i;
            while (temp) {
                if (temp % 10 == 0)
                    break;
                else {
                    if (i % (temp % 10) != 0)
                        break;
                    else {
                        temp = temp / 10;
                        if (temp == 0)
                            ans.push_back(i);
                    }
                }
            }
        }
        return ans;
    }
};
```
