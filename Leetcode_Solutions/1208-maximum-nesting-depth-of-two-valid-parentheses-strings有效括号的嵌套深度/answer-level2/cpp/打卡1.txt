### 解题思路
  因为它要是max(depth(A),depth(B))最小，那就只能将括号进行对半分，这样能使得这个值是尽可能的小。
  现在直到需要进行对半分，那是随便的进行括号乱分吗。首先，得知道它的嵌套深度。那嵌套深度其实就是“（”的个数。但是，根据题目给的嵌套深度的定义，（）（）的深度是一样，而（（））这样的情况就只需要数（的个数就行了。
  比如： ()(())()  对应的深度   11122122
  因此，只需要去进行奇偶数去对分就可以了。

### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> r;
        int n = seq.size();
        int s = 0;
        for(int i = 0 ; i < n ; i++){
            if(seq[i] == '('){
                s++;
                r.push_back(s%2);
                
            }
            else{
                r.push_back(s%2);
                s--;
            }
        }
        return r;
    }
};
```