由题意可以得出，当遍历字符串“遇到”字符时会发生两种结果：

 - 当 'A' <= S[i] <= 'Z' 时， 包括S[i]大写在内共有两种组合；
 - 当 'a' <= S[i] <= 'z' 时， 包括S[i]小写在内也共有两种组合；
 - 当 '0' <= S[i] <= '9' 时， 只有一种组合；

根据**回溯法**可以大致推出代码：
```
class Solution {
private:
    unsigned int strLen;	//	S 字符串的长度
    vector<string> result;	//	组合结果
public:
    vector<string> letterCasePermutation(string S) {
        this->strLen = S.length();
        generate(0, S);
        return result;
    }

    void generate(int i, string S){
        if(i == strLen){
        	//	已经“遍历”完S字符串的最后一个字符
            result.push_back(S);	//	将这个结果插入到result 中
            return;
        }
        if(S[i] >= 'A' && S[i] <= 'Z'){
        	//	情况 1
            generate(i+1, S);
            //	原字符是大写，现在进行小写情况的推理
            S[i] += 32;
            generate(i+1, S);
        }
        else if(S[i] >= 'a' && S[i] <= 'z'){
        	//	情况 2
            generate(i+1, S);
            //	原字符时小写，现在进行大写情况的推理
            S[i] -= 32;
            generate(i+1, S);
        }
        else{
        	//	数字一遍过
            generate(i+1, S);
        }
    } 
};
```
