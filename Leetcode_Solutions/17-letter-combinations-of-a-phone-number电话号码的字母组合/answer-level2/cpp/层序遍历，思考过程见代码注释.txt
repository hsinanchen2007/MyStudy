### 解题思路
层序遍历，过程思考和注释见代码过程,思考和尝试过程走了些弯了，解题时间没少花  ：（

### 代码

```cpp
class Solution {
private:
    map<char, string> m_letter_table;
    void construct_letter_table() {
        m_letter_table.insert(pair<char, string>('2', "abc"));
        m_letter_table.insert(pair<char, string>('3', "def"));
        m_letter_table.insert(pair<char, string>('4', "ghi"));
        m_letter_table.insert(pair<char, string>('5', "jkl"));
        m_letter_table.insert(pair<char, string>('6', "mno"));
        m_letter_table.insert(pair<char, string>('7', "pqrs"));
        m_letter_table.insert(pair<char, string>('8', "tuv"));
        m_letter_table.insert(pair<char, string>('9', "wxyz"));
    }

public:
    //Begin TIME : 2020.3.21 20：20
    //FINISHING TIME: 2020.3.21 22:13
    //采用map<char, string> 来存放映射表
    //解析输入的字符，转化为数字，查映射表，进行结果组合
    //结果组合并非前面考虑的几层循环嵌套那么简单，一方面效率有问题，另一方面循环不太好写
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.length() == 0) {
            return res;
        }

        //构建映射表
        construct_letter_table();        

        //查表并构建结果
        //无法使用循环写，因为随着nums.size()的不同，循环层数是动态的
        //需要使用广搜,一层一层遍历，并把新的字符加入到结果中
        queue<string> Q;
        string option_res;

        //第数字对应字母字符串入队列，作为第0层
        for (int i = 0; i < m_letter_table[digits[0]].length(); ++i){
            string s;
            s.push_back(m_letter_table[digits[0]][i]);
            //cout<<s<<endl;
            Q.push(s);
        }
        
        for (int i = 1; i < digits.size(); ++i) {
            int len = Q.size(); //逐层插入字符到队列中，每层搜索相当于每个数字对应的字符
            //cout<<"queue len"<<len<<endl;
            //把每个数字对应的候选字母都出现一次
            while (len--) {

                for (int k = 0; k < m_letter_table[digits[i]].length(); ++k){
                    option_res = Q.front(); //例如取出2对应的 a b c中的a
                    string tmp_str = "";
                    tmp_str.push_back(m_letter_table[digits[i]][k]);
                    option_res = option_res + tmp_str;
                    Q.push(option_res);
                    //cout<<"enqueue "<<option_res<<endl;  
                }

                Q.pop(); //例如将2对应的 a b c中的a 从队列中弹出，因为2组合的已经组合OK并且有ad ae af之类的组合存入队列中了  

            }
        }
        //cout<<"queue len 2 = "<<Q.size()<<endl;
        //此时存放在Q中的就是所有可能的组合，将queue结构转换成vector结构，进行函数返回
        while (!Q.empty()) {
            res.push_back(Q.front());
            Q.pop();
        }
        
        return res;

    }
};
```