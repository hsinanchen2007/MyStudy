### 解题思路
* 抓住必要条件：所有元素的总和是3的倍数
* 找到第一部分和sumi = sum / 3；再找到第二部分和sumj = sum / 3。找不到其中之一都返回false。

### 代码

```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0;
        for(int i: A) 
            sum += i;
        if(sum % 3)         // 必要条件：所有元素的总和是3的倍数
            return false;
        sum = sum / 3;

        int i = 0, j = 0;
        int sumi = 0, sumj = 0;
        for(int a: A) {
            sumi += a;
            if(sumi == sum) break;
            i++;
        }
        if(i == A.size()) return false;

        for(j = i+1; j < A.size(); j++) {
            sumj += A[j];
            if(sumj == sum) break;
        }
        if(j >= A.size() - 1) return false;

        return true;
    }
};
```
* 存疑：可能是使用了for(int a: A)结构，耗时比价高。
![2.png](https://pic.leetcode-cn.com/986d93bbe65c21b4ca7e9ea050288b3ef08a02cda89cb3ca8cd669c25d2516e6-2.png)
