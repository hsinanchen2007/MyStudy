### 解题思路
写成了简单但是不容易看懂的样子

### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
       
        if(seq.empty()){
            return vector<int>();
        }
        int len = seq.length();
        vector<int> ans(len, 0);
     
      
        for(int i=0; i<len;i++){
            if( seq[i] == '('){
                ans[i] = i&1;
            }else if(seq[i] == ')'){
                ans[i] = (i&1)^1;
            }
        }
        
        return ans;
    }
};

```