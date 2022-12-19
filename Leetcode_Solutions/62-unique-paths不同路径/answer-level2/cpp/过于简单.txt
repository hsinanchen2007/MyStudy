![捕获.PNG](https://pic.leetcode-cn.com/7ccf0c3e45252320647b57795f1ab36abae615e3df72f19ddf305588c4011b03-%E6%8D%95%E8%8E%B7.PNG)

### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m <= 0 || n <= 0) return 0;
        int arr[m];
        for(int i=0;i<m;i++) arr[i] = 1;
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){arr[j] += arr[j-1];}
        }
        return arr[m-1];
    }
};
```