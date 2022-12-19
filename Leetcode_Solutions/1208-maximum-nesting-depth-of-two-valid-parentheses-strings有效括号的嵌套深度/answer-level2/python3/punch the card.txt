### 解题思路

Kick in the card. 
Again, I will give you code. 

### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> out;
        
        for(int i=0;i<(int)seq.size();i++)
        {
            if(i%2==0)
                out.push_back(seq[i]=='('?1:0);
            else
                out.push_back(seq[i]==')'?1:0);
        }
            return out;
    }


        
private:
};



```