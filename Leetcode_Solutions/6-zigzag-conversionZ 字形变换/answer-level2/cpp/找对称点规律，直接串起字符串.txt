### 解题思路
        每一个z字形的角为一个对称点，把对称点依次串起；

### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        if(n<=1||numRows==1) return s;

        string z;
        for(int i=0;i<numRows;++i){
            int curr=i;
            int mid=numRows-1;
            while(curr<n){
                z.push_back(s[curr]);
                if(curr==mid)
                mid+=numRows-1;
                curr+=2*(mid-curr);
                mid+=numRows-1;
            }
        }
        return z;

    }
};
```