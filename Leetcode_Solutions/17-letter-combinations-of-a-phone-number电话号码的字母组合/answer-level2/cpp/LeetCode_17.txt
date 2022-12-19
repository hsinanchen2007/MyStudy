### 解题思路
此处撰写解题思路:先把数字映射的字符串存入队列，再把队列前两个字符串组合，再把后续的字符串与之前的组合再进行组合，不断更新组合的字符数组，直到队列最后一个元素被组合，返回。注意要处理数字字符串为空或者只有一个数字的情况，思路详见代码
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :6.6 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        deque<string> deq;  /*队列保存数字到字母的映射*/
        int n=digits.size();
        //string str; /*暂存映射值，用于进队列*/
        vector<string> v_str;   /*组合的字符串数组*/
        vector<string> result;  /*返回的字母组合*/
        if(digits.empty())  return result;  /*若数字字符为空，直接返回*/
        for(int i=0;i<n;++i){
            switch(digits[i]){  /*把数字对应的映射存入队列*/
                case '2':
                    deq.push_back("abc");
                    break;
                case '3':
                    deq.push_back("def");
                    break;
                case '4':
                    deq.push_back("ghi");
                    break;
                case '5':
                    deq.push_back("jkl");
                    break;
                case '6':
                    deq.push_back("mno");
                    break;
                case '7':
                    deq.push_back("pqrs");
                    break;
                case '8':
                    deq.push_back("tuv");
                    break;
                case '9':
                    deq.push_back("wxyz");
                    break;
                default:
                    break;
            }
        }
        if(deq.size()==1){  /*若队列中只有一个元素，则返回由该元素每个字符组成的字符串数组*/
            string str=deq.front();
            for(int i=0;i<str.size();++i){
                result.push_back(str.substr(i,1));
            }
            return result;
        }
        string first=deq.front();   /*取队列头元素*/
        deq.pop_front();    /*头元素出队列*/
        string second=deq.front();  /*取第二个元素*/
        deq.pop_front();    /*出队列*/
        for(int i=0;i<first.size();++i){    /*前两个字符串字母组合*/
            for(int j=0;j<second.size();++j){
                v_str.push_back(first.substr(i,1)+second.substr(j,1));  /*存入字符串数组*/
            }
        }
        result=v_str;
        v_str.clear();  /*清空临时数组，用于下一次保存字母组合*/
        auto beg=deq.begin();   /*迭代器指向此时队列头元素*/
        while(beg!=deq.end()){
            for(int i=0;i<(*beg).size();++i){
                for(auto s:result){
                    v_str.push_back(s+(*beg).substr(i,1));
                }
            }
            result=v_str;
            v_str.clear();  /*清空临时数组，用于下一次保存字母组合*/
            ++beg;
        }
        return result;
    }
};
```