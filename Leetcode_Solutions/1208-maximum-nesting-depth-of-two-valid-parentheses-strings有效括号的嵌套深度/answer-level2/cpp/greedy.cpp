### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int len=seq.size();
        stack<int> words;
        vector<int> fin(len,0);
        words.push(0);
        
        for(int i=1;i<len;i++)
        {
            char temp=seq[i];
            if(temp=='(' )
            {
                if( seq[i-1]=='(' )
                    fin[i]=1-fin[i-1];
                else
                    fin[i]=fin[i-1];
                words.push(i);
            }
            else
            {
                int te=words.top();
                fin[i]=fin[te];
                words.pop();
            }
        }
        return fin;
    }
};
```