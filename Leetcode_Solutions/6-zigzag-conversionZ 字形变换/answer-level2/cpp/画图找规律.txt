### 解题思路
1. 对于所有行，每隔 2*numRows - 2 个元素，输出一个垂直方向上的元素
2. 对于中间行（即除去第一行和最后一行），除了输出一个垂直方向上的元素外，每隔 2*numRows - 2*c 个元素，还需输出一个45度方向上的元素
### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if(s.size()==0||s.size()==1||numRows==1) return s;
        int c=1;
        int c_cycle = 2*numRows - 2;
        string res;
        for(int i=0; i<numRows; i++){
            int per_cycle = 2*numRows - 2*c;
            for(int j=i; j<n; j = j+c_cycle){
                res.push_back(s[j]);
                if(c!=1 && c!=numRows && j+per_cycle<n){
                    res.push_back(s[j+per_cycle]);
                }
            }
            c++;
        }
        return res;
    }
};
```