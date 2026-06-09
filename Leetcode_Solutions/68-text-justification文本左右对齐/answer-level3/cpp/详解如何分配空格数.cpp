### 解题思路
一、这个问题的难点在于**如何控制每个间隔中的空格数**,即a个空格如何按照规则分到b个间隔中去
### getBlank(int a, int b)方法
首要考虑**平均分**，其次考虑**左大于右**
既然要平均分，则有a/b, 若有余数，说明必有多的空格放在靠前的间隔里（左大于右），这里利用向上取整函数ceil，获得最左边间隔的空格数c
然后将a依次分配c个出去，同时监控是否可以平分，若可平分(包括只剩一个间隔b=1)则剩余间隔均有a/b个空格，程序结束

在这个过程中，同学们会注意到万一a<c不够分了怎么办？
实际上，在这个过程中，首先检验的是当前剩余空格是否可平均分至间隔中，如果有a<c的情况，在它之前便已经出现可均分的情况，于是便无需考虑a<c的情况。
至于为什么，只能说找的规律，恕在下数理基础薄弱不能给出数学证明，哪位同学可以给予证明或解释感激不尽！

二、还有一点是如何**判断当前的单词应不应该加入当前行**
考虑极限的情况：每个单词之间只有一个空格，且所有字母的总长度+空格数=maxWidth
可以以此来决定当前单词是否加入当前行，即如果在极限的情况下都大于maxWidth，这个单词必然不能在当前行
维护以下变量：
textLen: 当前行的字母长度，不包含空格
i: 当前单词的index
begin: 当前行起始单词的index
其中i-begin便是当前单词与起始单词之间的间隔数
如果textLen+words[i].size()+i-begin<=maxWidth，那么这个单词就可以加入当前行
### 代码

```cpp
class Solution {
public:
    // 获取a个空格分到b个间隔的分法，首要考虑平均分，其次考虑左大于右
    vector<int> getBlank(int a, int b){
        int c;
        vector<int> res;
        c = ceil((double)a/b);
        while(b>0){
            // a不可平分至b时，输出最开始的c值
            if(a/b != ceil((double)a/b)){
                a -= c;
                b--;
                res.push_back(c);
            }else{	// 一旦出现a可平分至b，则直接输出a/b 
                c =  a/b; // 记录平分值 
                while(b>0){
                    res.push_back(c);
                    b--;
                }
                return res;
            }
        }
        return res;
    }
    // 获取在begin与end间单词格式化后的结果
    string getString(vector<string>& words, int maxWidth, int textLen, int begin, int end){
        string res;     // result
        int num = end-begin;        // 单词间隔的个数
        int blankLen = maxWidth-textLen;    // 空格的个数
        if(num == 0){   // 仅有一个单词
            res += words[begin];
            res += string(blankLen, ' ');
            return res;
        }
        vector<int> blank = getBlank(blankLen, num);    // 每个间隔中应该添加的空格数
        vector<int>::iterator t = blank.begin();
        for(int i=begin; i<=end; i++, t++){
            res += words[i];
            if(t!=blank.end())
                res += string(*t, ' ');
        }
        return res;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int num = words.size();     // 单词的个数
        int textLen=0;      // 当前行的字母长度，不包含空格
        int begin=0, end;   // 当前行的字母在words中的index
        string curStr;      // 格式化后的当前行
        vector<string> res;     // result
        for(int i=0; i<num; i++){
            // i-begin: 到目前为止字母间的最小空格数
            if(textLen+words[i].size()+i-begin<=maxWidth){ // 判断加上当前单词是否还有空间
                textLen += words[i].size();
            }else{
                end = i-1;
                curStr = getString(words, maxWidth, textLen, begin, end); 
                res.push_back(curStr);
                textLen = words[i].size();
                begin = i;
            }
        }
        // 上述代码导致至少最后一个单词未进行格式化(end=i-1)，不过begin已记录最后一行的起始位置
        curStr = "";
        for(int i=begin; i<num; i++){
            curStr += words[i];
            if(curStr.size()==maxWidth)
                break;
            curStr += ' ';
        }
        if(curStr.size()<maxWidth)
            curStr += string(maxWidth-curStr.size(), ' ') ;
        res.push_back(curStr);
        return res;
    }
};
```