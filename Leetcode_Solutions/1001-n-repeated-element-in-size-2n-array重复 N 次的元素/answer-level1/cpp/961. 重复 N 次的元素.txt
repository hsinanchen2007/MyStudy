![222.png](https://pic.leetcode-cn.com/e8a1d90318964dc7e0ef769afe8d3464c4a0c1ccd4d010a8263936a98c976478-222.png)

```
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        set<int> a;
        int n=A.size();
        int tmp=0;
        for(int i=0;i<n;++i)
        {
            tmp=A[i];
            if(a.find(tmp)==a.end())
            {
                a.insert(tmp);
            }
            else
            {
                return tmp;
            }
        }
        return tmp;
    }
};
```
