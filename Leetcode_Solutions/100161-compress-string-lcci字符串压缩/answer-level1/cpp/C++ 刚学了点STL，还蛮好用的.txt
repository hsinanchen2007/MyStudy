### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string compressString(string S) {
        int size = S.size();
        int i=0;
        string result;
        while(i<size){
            result.push_back(S[i]);
            int count=1;
            while(i<size&&S[i+1]==S[i]){
                ++i;
                count++;
            }
            if(count<10)
                result.push_back('0'+count);
            else{
                string tmp;
                while (count!=0){
                    tmp.push_back(count%10+'0');
                    count/=10;
                }
                for(auto pr=tmp.end()-1;pr>=tmp.begin();pr--)
                    result.push_back(*pr);
            }
            ++i;
        }
        return result.size()>=size?S:result;
    }
};
```