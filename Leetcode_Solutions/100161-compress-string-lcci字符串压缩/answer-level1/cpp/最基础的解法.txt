### 解题思路
此处撰写解题思路

### 代码
首先定义一个空字符串作为结果串，get到S串的长度之后用for循环遍历比较。最后比较一下结果串和初始串的长度，哪个短输出哪个
```cpp
class Solution {
public:
    string compressString(string S) {
        string temp = "";
        int strLength = S.size();
        int count = 1;
        for(int i = 0;i<strLength;i++){
            char key = S[i+1];
            if(key == S[i]){
                count++;
            }else{
                temp+=S[i] + to_string(count);
                count = 1;
            }
        }
        if(temp.size() < strLength){
            return temp;
        }
        return S;
    }
};
```