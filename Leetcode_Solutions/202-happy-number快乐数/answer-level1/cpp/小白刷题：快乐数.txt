如果不是快乐数，过程一定会无限循环，那么也就是说，一定会到某一步，得到的数在记录中出现过

因此设一个set对过程每一步的结果进行记录，一旦某一步的结果不为1且在记录中能找到，就说明出现循环，也就是说数不是快乐数

如果结果为1，当然说明就是快乐数了

代码：
```
class Solution {
public:
    bool isHappy(int n) {
        set<int> record;
        int temp = n;
        while (record.find(temp) == record.end()) {
            record.insert(temp);
            int ans = 0;
            while (temp) {
                ans = ans + (temp % 10) * (temp % 10);
                temp = temp / 10;
            }
            if (ans == 1)
                return true;
            else
                temp = ans;
        }
        return false;
    }
};
```
