### 解题思路
暴力遍历所有的可能对称中心，即所有的字符和字符间隔
![1.png](https://pic.leetcode-cn.com/556a84b70d35ddeba0d5f213952076701f99deb4b5a752ca1afb47c54988d58a-1.png)

### 代码

```cpp
class Solution {
public:
    int countSubstrings(string s) {
        int part1 = 0;
        for(int i=0;i<s.size();++i){
            int le = i-1;
            int ri = i+1;
            while(le>=0&&ri<s.size()&&s[le]==s[ri]){
                le--;
                ri++;
            }
            part1+=(ri-le-1)/2+1;
        }
        int part2 =0;
        for(int i=0;i<s.size()-1;i++){
            int le = i;
            int ri = i+1;
            while(le>=0&&ri<s.size()&&s[le]==s[ri]){
                le--;
                ri++;
            }
            part2+=(ri-1-le)/2;
        }
        return part1+part2;
    }
};
```