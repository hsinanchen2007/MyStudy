![fsdfdsfsdfds.PNG](https://pic.leetcode-cn.com/10321007f00da71955370af69ab79ccb802ae543fd6ffed86cfd2427ae1ed6c1-fsdfdsfsdfds.PNG)

```
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        return string(s.begin()+n,s.end())+string(s.begin(),s.begin()+n);
    }
};
```

