### 解题思路
  因为计算的是相连的部分，因此就只需要一个一个找过去就可以了。碰到与前一个相同的就个数加一，不相同的就把前者添加到字符串中。再接着找下一个。因为我是找与前一个是否相同，并且在不相同的时候处理。因此，肯定会有最后一个或相同的多个没有加入字符串，所以循环结束后，要进行加入。
  最后，只需要比较新得到的字符串长度是否小于原字符串，如果小于就返回新字符串，否则返回原字符串就ok了。

### 代码

```cpp
class Solution {
public:
    string compressString(string S) {
        string s = "";
        int d = 1;
        for(int i = 1 ; i < S.length() ; i++){
            if(S[i] == S[i - 1])d++;
            else{
                s += S[i - 1];
                s += to_string(d);
                d = 1;
            }
        }
        if(d){
            s += S[S.length() - 1];
            s += to_string(d);
        }
        return s.length() < S.length() ? s : S;
    }
};
```