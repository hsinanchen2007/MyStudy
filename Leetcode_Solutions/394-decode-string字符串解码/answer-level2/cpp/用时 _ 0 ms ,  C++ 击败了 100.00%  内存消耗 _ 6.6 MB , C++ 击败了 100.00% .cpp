
迭代法  代码不是很优美 但是结果还可以。

```
class Solution {
public:
    string decodeString(string s) {
        stack<int> num;  stack<string> pre;
        string ans;  string cur;
        int left = 0;  // 统计是否有嵌套
        for(int i = 0; i<s.size(); ++i){
            auto str = s[i];
            if(isdigit(str)){  // 如果是数字  将倍数压入栈中
                int j = i+1;
                while(isdigit(s[j])) ++j; 
                string tmp = s.substr(i,j-i);
                num.push(stoi(tmp));
                i = j-1;
            }else if(str=='['){   // 碰到左括号 
                if(left==0 && !cur.empty()) ans += cur;  // 如果当前不在一个未处理的左括号内 并且当前的字符串非空 就将当前字符串加入答案
                if(left!=0) pre.push(cur);   // 否则因为有需要处理的左括号，需要将当前字符压入栈中
                ++left;
                cur.clear();  // 当前字符串清零 因为要开始重复左括号内的元素
            } else if(str==']'){   
                auto cnt = num.top(); // 先重复n次
                num.pop();
                string tmp = cur; 
                while(--cnt)
                    cur += tmp;    
                if(left>1){  // left大于1说明 前面还有一个未处理的左括号
                    cur = pre.top()+cur;   // 需要把之前的字符串加在当前字符串上
                    pre.pop();
                } 
                --left;
            } else cur += str;   // 累加字符串
        }
        if(!cur.empty()) ans += cur;  // 结束后把还没加入答案的子串加入答案
        
        return ans;
    }
};
```



