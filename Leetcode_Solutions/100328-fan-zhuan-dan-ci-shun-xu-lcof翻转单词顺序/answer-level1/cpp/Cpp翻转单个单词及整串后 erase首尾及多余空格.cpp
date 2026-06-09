### 解题思路
先翻转单个单词，后翻转整个字符串
最后，会出现首、尾元素是空格的情况，erase去除
中间也会出现多个空格连接的情况，仅保留一个

### 代码

```cpp
class Solution{
public:
void ChangePos(string &s,int begin ,int end){//翻转函数；
    while(begin<end){
        char temp = s[begin];
        s[begin] = s[end];
        s[end] = temp;
        begin ++;
        end --;
    }
}
void trim1(string &s){//删除首||尾空格函数；
    if( !s.empty() ){
        s.erase(0,s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
    }
}
void trim2(string &s){//在任意单词中间有多个空格时仅保留一个；
    int i = 0,j = 1;
    if(!s.empty()){
        while(i<s.size()-1){
            if(s[i] == ' ' && s[j] == ' '){
                while(s[j] == ' '){//统计该空格群中有多少个空格；
                    j++;
                }
                s.erase(i,j-1-i);
                j = i+1;//删除完后再返回到i的后面；
                }
            else{//依次排查
                i++;
                j++;
                }
        }
    }
}

string reverseWords(string s) {
    bool flag = false;//flag联想OS里的红绿灯交通管制PV题，
                      //在这里负责管理是单词的前进读取还是下一个单词的开始；
    int begin = 0,end = 0;
    for (int i = 0;i < s.size();i++){
        if (s[i]!=' '){
            if (!flag){//标志着这是一个新的单词开始；
                flag = true;
                begin = i;
            }
        }
        else{//为' '则表示上一个单词读取结束，可以将上个单词翻转；
            if(flag){//如果第一个元素是' '则不进行；
                ChangePos(s,begin,i-1);
                flag = false;
            }
        }
        if(i == s.size()-1 && s[i]!=' '){//当最后一个单词不是以' '结束的时候也要把最后一个翻转；
        ChangePos(s,begin,s.size()-1);
        }
    }
    ChangePos(s,0,s.size()-1);//更改完后会出现s[]首尾有' '的情况；
    if(s[0] == ' ' || s[s.size()-1] == ' '){//头或尾出现空格要删去
        trim1(s);
    }
    trim2(s);//中间出现多个空格要保留一个
    return s;
}
};
```