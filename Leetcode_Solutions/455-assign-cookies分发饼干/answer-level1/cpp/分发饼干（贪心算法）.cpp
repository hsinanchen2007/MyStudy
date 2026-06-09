### 解题思路
1. 对胃口值数组g和饼干值数组s进行从小到大排序；
2. 按照从小到大的顺序使用各饼干尝试是否可以满足某个孩子，每个饼干只能尝试一次；
3. 尝试成功，则换下一个孩子尝试；直到发现没有更多的孩子或者没有更多的饼干，循环结束。

![image.png](https://pic.leetcode-cn.com/3c8052fa3c58448b861d29da2b87d363b753ea2d127f3f967fc94f90598e94d1-image.png)
![image.png](https://pic.leetcode-cn.com/26ab41561196eebe3c916aeec3ccb3485a8a03ac2b538ab7d90f5e975a11ebb7-image.png)

### 代码

```cpp
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());  //排序
        sort(s.begin(), s.end());
        int i=0, j=0;
        while(i < g.size() && j < s.size()){
            if(g[i] <= s[j]){
                i++;    //满足孩子
                //j++;    //糖果只比较一次
            }
            j++;    //无论是否满足孩子，都进行下一个比较
        }
        return i;
    }
};
```