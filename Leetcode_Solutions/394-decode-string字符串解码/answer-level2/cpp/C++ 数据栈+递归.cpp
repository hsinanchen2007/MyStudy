// 1.将源字符串逐字符压栈，直到遇见‘]’说明已经出现了一个需要解码的字段
// 2.弹栈找到‘[’记录[]之间的字符串，弹出来的是逆序，需要反转
// 3.解析k值，然后根据解码规则创建一个k次重复的字符串
// 4.将新字符串替换源字符串需要解码的部分，得到解码一次的字符串
// 5.将解码一次的字符串作为源字符串递归

// 题解区还有不少大佬，的优秀解法，其实你也可以随便找一个先通过测试，然后查看排名中性能最优的算法是怎么做的
// 不过都没注释也不方便看😄


// ```
class Solution {
public:
    string decodeString(string s) {
        string ret;
        stack<char> mystack;
        if(s.find('[')<s.size()){
            for(char mem:s){//将第一个需要解码的关键字压栈，即第一个以‘]’结束的字段
                if(mem!=']'){
                    mystack.push(mem);
                    continue;
                }else break;
            }
            string substr_tmp;
            while(mystack.top()!='['){//取出第一个需要解码的关键字，然后根据k值解码
                substr_tmp.push_back(mystack.top());
                mystack.pop();
            }
            reverse(substr_tmp.begin(),substr_tmp.end());
            mystack.pop();
            int i = 0;
            int key = 0;
            while((mystack.top()-'0')>=0 && (mystack.top()-'0')<10){
                key += pow(10,i)*(mystack.top()-'0');
                mystack.pop();
                i++;
                if(mystack.empty())
                    break;
            }
            string substr_replace;
            while(key>0){
                substr_replace.append(substr_tmp);
                key--;
            }                       //完成第一个关键字的解码，然后替换源字符串中的内容
            int pos = s.find(']')-substr_tmp.size()-1-i;
            s.erase(pos,substr_tmp.size()+2+i);
            s.insert(pos,substr_replace);

            ret = decodeString(s);//递归
            return ret;
        }
        ret = s;
        return ret;
    } 
};
// ```

