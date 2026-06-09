### 解题思路
![image.png](https://pic.leetcode-cn.com/0bbb59089614ee9300017fe61433d98b9e59e7d5d7df07b69b4bab525fdcf413-image.png)


### 代码

```cpp
class Solution {
public:
    bool isUnique(string astr) {
        if(astr.size()==0)return 1;
        sort(astr.begin(),astr.end());
        for(int i=1;i<astr.size();++i)
        {
            if(astr[i]==astr[i-1])return 0;
        }
        return 1;
    }
};
```