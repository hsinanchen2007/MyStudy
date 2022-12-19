### 解题思路
这种题目往往有坐标的对应关系，多想一想就知道了

### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        string re;
        if (numRows==1) return s;
        //i是行，i<numRows是为了避免行数比数组长度还大的情况
        for (int i=0; i<numRows && i<s.size(); i++) {
            //用于翻转状态
            bool fsm = true;
            int j=i;
            //j对应原始数组下标，初始也即每行的第一个元素下标就是i。
            while (j<s.size()) {
                int gap = fsm ? 2*(numRows-i-1):2*i;
                fsm = !fsm;
                //第一行和最后一行会出现重复，这一行是为了避免
                if (gap == 0) continue;
                re.push_back(s[j]);
                j += gap;
            }
        }
        return re;
    }
};
```