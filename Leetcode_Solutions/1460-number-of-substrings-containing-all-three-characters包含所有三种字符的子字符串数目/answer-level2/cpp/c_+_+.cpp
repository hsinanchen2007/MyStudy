### 解题思路
![image.png](https://pic.leetcode-cn.com/33538b3931e0795acfb062cea512396b39b4902ee7ab4c789d9d6e31909ab773-image.png)

### 代码

```cpp
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int a = 0, b = 0, c = 0;
        int ans = 0;
        for(int i = 0, last = 0;i < n;++i){
            if(s[i] == 'a') ++a;
            if(s[i] == 'b') ++b;
            if(s[i] == 'c') ++c;
            while(a > 0 && b > 0 && c > 0 && last <= i - 2){
                ans += n - i;
                if(s[last] == 'a') --a;
                if(s[last] == 'b') --b;
                if(s[last] == 'c') --c;
                ++last;
            }
        }
        return ans;
    }
};
```