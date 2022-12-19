### 解题思路
![image.png](https://pic.leetcode-cn.com/413d5dcd6aba19a3e214a3598ca3d86f128e2cbe6667d19930012c6a7f338fc4-image.png)

采用的是冒泡的算法，单个字符循环遍历

### 代码

```cpp
class Solution {
public:
    bool isUnique(string astr) {
        int len = astr.length();
        for(int begin =0;begin<len;begin++){
            for(int cmp = begin+1;cmp<len;cmp++){
                if(astr[begin] == astr[cmp]){
                    return false;
                }
            }
        }
        return true;
    }
};
```