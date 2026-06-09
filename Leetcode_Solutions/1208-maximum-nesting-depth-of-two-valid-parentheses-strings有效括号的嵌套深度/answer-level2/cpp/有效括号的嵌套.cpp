### 解题思路
参考博客：https://blog.csdn.net/qq_17550379/article/details/95368173
对四种情况进行分配。
![image.png](https://pic.leetcode-cn.com/5e6c5a8b628b1926549ae768c9c50bace9d4bf9d97b256027f5383d89476582f-image.png)

### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res;
        for(int i = 0; i < seq.size(); i++){
            if(seq[i] == '(' && (i%2)) res.push_back(0);
            else if(seq[i] == '(' && !(i%2)) res.push_back(1);
            else if(seq[i] == ')' && (i%2)) res.push_back(1);
            else if(seq[i] == ')' && !(i%2)) res.push_back(0);
        }
        return res;
    }
};
```