这道题是求最大深度，且不能出现（）（），第一个属于括号属于A，第二个属于B，这种情况

那么可以遇到（，深度加：`++deep`，遇到），深度`deep--`，这样将奇数深度给A，偶数深度给B，或相反。
```
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res(seq.size(),0);
        int level = 0, index = 0;
        while(index < seq.size()){
            if(seq[index] =='(')
                res[index] = ++level%2;
            else
                res[index] = level--%2;
            index++;
        }
        return res;
    }
};
```
另外可以不用额外空间

```
 public int[] maxDepthAfterSplit(String seq) {
        int n = seq.length(), res[] = new int[n];
        for (int i = 0; i < n; ++i)
            res[i] = seq.charAt(i) == '(' ? i & 1 : (1 - i & 1);
        return res;
    }
```

