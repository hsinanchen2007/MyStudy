### 解题思路
先往 result 里 push 一个 "\0"
然后就遍历 S 里的元素
    如果是字母，就遍历 result 里的元素，在元素末尾加上相应的大小写字母
    如果是其他字符，就遍历 result 里e的元素，直接在末尾加上字符就行
然后就得到结果了

后来想到——我应该把分支写在循环里面
不过这样代码比较多，显得比较牛逼，我就不写了

按理说应该用回溯

### 代码

```cpp
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> result;
        vector<string> tempres;
        int length = S.size();
        string temp = "";
        char alpha = 'a';
        int lastlength = 0;
        result.push_back("\0");
        for(int i = 0; i < length; i++){
            lastlength = result.size();
            if(S[i] >= 'a' && S[i] <= 'z'){
                for(int j = 0; j < lastlength; j++){
                    temp = result[j] + S[i];
                    tempres.push_back(temp);
                    alpha = S[i] - 32;
                    temp = result[j] + alpha;
                    tempres.push_back(temp);
                }
            }else if(S[i] >= 'A' && S[i] <= 'Z'){
                for(int j = 0; j < lastlength; j++){
                    alpha = S[i] + 32;
                    temp = result[j] + alpha;
                    tempres.push_back(temp);
                    temp = result[j] + S[i];
                    tempres.push_back(temp);
                }
            }else{
                for(int j = 0; j < lastlength; j++){
                    temp = result[j] + S[i];
                    tempres.push_back(temp);
                }
            }
            result = tempres;
            tempres.clear();
        }
        return result;
    }
};
```