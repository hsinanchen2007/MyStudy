### 解题思路
c++

### 代码

```cpp
class Solution {
public:
    vector<int> printNumbers(int n) {

        string cut(n, '0');

        vector<int> res;
        while (incNum(cut))
        {
            //printNum(cut, res);
            //cout << cut << " ";
            res.push_back(stoi(cut));
        }

        return res;
    }
    bool incNum(string& cut) {
        int end = cut.size() - 1;

        if (cut[end] < '9') {
            ++cut[end];     //末位相加
        }
        else {
            cut[end] = '0'; 
            while (end - 1 >= 0 && cut[end - 1] == '9') { //判断进位长度
                cut[--end] = '0';
            }
            if (end == 0)   //end = 0表示 进位溢出
            {
                return false;  //不能在增长
            }
            ++cut[end - 1];     //进位加一
        }
        return true;
    }
};
```