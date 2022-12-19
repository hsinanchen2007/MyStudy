### 解题思路
自己写的代码有点过于繁琐了，有空得改改

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> re;
        if (n==0) return re;
        if (n==1) {
            re.push_back(vector<int>(1,1));
            return re;
        }
        vector<int> line(n, 0);
        re.resize(n, line);
        int i=0, j=0;
        int num = 1;
        int leftbound = -1, rightbound = n, upbound = -1, downbound = n;
        //是用来防止加过头的标志量
        bool mark = false;
        //最后一个点：i=n/2，j=(n-1)/2
        while (!(i==n/2 && j==(n-1)/2)) {
            mark = false;
            while (j<rightbound) {
                re[i][j++] = num++;
                mark=true;
            }
            if (mark) {
                num--;
                j--;
            }
            upbound++;
            mark = false;
            while (i<downbound) {
                re[i++][j] = num++;
                mark = true;                
            }
            if (mark) {
                num--;
                i--;
            }
            rightbound--;
            mark = false;
            while (j>leftbound) {
                re[i][j--] = num++;
                mark = true;                
            }
            if (mark) {
                num--;
                j++;
            }
            downbound--;
            mark = false;
            while (i>upbound) {
                re[i--][j] = num++;
                mark = true;                
            }
            if (mark) {
                num--;
                i++;
            }
            leftbound++;
        }
        return re;
    }
};
```