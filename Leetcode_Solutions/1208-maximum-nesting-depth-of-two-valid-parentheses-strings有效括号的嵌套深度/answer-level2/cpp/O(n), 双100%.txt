### 解题思路
1）找到最大深度
2）将深度大于最大深度一半的分给B

![image.png](https://pic.leetcode-cn.com/b9b5600eb1f747562a2b8cc86834cfa296375a5c1f19e237a39532102200b6b5-image.png)

### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int sz = seq.size();
        vector<int> res(sz, 0);
        int level = 0;
        int cur = 0;
        for(char ch : seq){
            if(ch == '('){
                cur++;
                level = max(level, cur);
            }else{
                cur--;
            }
        }
        int half = (1+level)/2;
        bool begin = false;
        cur = 0;
        for(int i = 0; i < sz; i++){
            char ch = seq[i];
            if(ch == '('){
                cur++;
            }else{
                cur--;
            }
            if(cur > half){
                begin = true;
                res[i] = 1;
            }else if(cur == half){
                if(begin){
                    res[i] = 1;
                }
            }else{
                begin = false;
            }
        }
        return res;
    }
};
```