### 解题思路
保持一个变量last，遍历字符串的时候与last比较。
如果相同，就计数+1，继续往前遍历；
如果不同，就令计数为0，更新last，继续往前遍历。

### 代码

```cpp
class Solution {
public:
    string compressString(string S) {
        if (S.size()==0 || S.size()==1) return S;
        int count=0;
        char last='1';//非字母的字符
        string re;
        for(int i=0; i<S.size(); i++){
            if (S[i] != last){//不同的字符
                re+=last+to_string(count);
                last = S[i];
                count=1;
                continue;
            }
            else{//相同的字符
                count++;
            }
        }
        re+=last+to_string(count);
        re.erase(0,2);//抹去“11”
        if (re.size()>=S.size()) return S;
        else return re;
    }
};
```