### 方法一，用栈保存
一种用栈实现的方法，有点傻，主要是处理detail的时候太tricky了。
### 
执行用时 :4 ms, 在所有 C++ 提交中击败了98.61%的用户。内存消耗 :9.8 MB, 在所有 C++ 提交中击败了100.00%的用户
```cpp
class Solution {
public:
    string reverseWords(string s) {
        string res;
        string tmp;
        stack<string> stk;
        int flag = 0;//处理全为空格的情况
        for(char c:s){
            if(c != ' '){flag = 1;break;}
        }
        if(flag == 0)return "";
        
        for(char c:s){
            if(c != ' '){
                tmp += c;
            }else if(c == ' ' && tmp != ""){//处理开头和中间连续空格的情况
                stk.push(tmp);
                tmp = "";
            }
        }

        res += tmp;//这里没有压栈，是为了while循环中写起来更方便
        if(tmp == ""){res += stk.top();stk.pop();}//处理末尾空格
        while(!stk.empty()){
            res += ' ';
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};
```
### 方法二，利用字符流 sstream 可以方便地解决掉空格问题

```cpp
class Solution {
public:
    string reverseWords(string s) {
        string ans, str;
        stringstream ss(s);
        while (ss >> str) ans.insert(0, str + " ");
        return ans.size() ? string(ans.begin(), ans.end() - 1) : "";
    }
};
不过上述方法耗时会达到50ms+，比较高，主要原因是每次都需要调用insert函数进行“逆序存储“”
下面改用“顺序存储逆序输出”，耗时可以降到4~10+ms
class Solution {
public:
    string reverseWords(string s) {
        string ans, str;
        vector<string> tmp;
        stringstream ss(s);
        while (ss >> str) tmp.push_back(str);
        for (int i = tmp.size() - 1; i >= 0; i--) ans += tmp[i] + " ";
        return ans.size() ? string(ans.begin(), ans.end() - 1) : "";
    }
};

作者：pris_bupt
链接：https://leetcode-cn.com/problems/reverse-words-in-a-string/solution/c-si-xing-dai-ma-ji-qi-you-hua-by-pris_bupt/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```

### 方法三、原地算法

解决思路是，先原地整体反转，再逐单词反转；需要处理首尾、中间的冗余空格。
```cpp
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());                        //整体反转
        int start = 0, end = s.size() - 1;
        while (start < s.size() && s[start] == ' ') start++;//首空格
        while (end >= 0 && s[end] == ' ') end--;            //尾空格
        if (start > end) return "";                         //特殊情况

        for (int r = start; r <= end;) {                    //逐单词反转
            while (s[r] == ' '&& r <= end) r++;
            int l = r;
            while (s[l] != ' '&&l <= end) l++;
            reverse(s.begin() + r, s.begin() + l);
            r = l;
        }

        int tail = start;                                   //处理中间冗余空格
        for (int i = start; i <= end; i++) {
            if (s[i] == ' '&&s[i - 1] == ' ') continue;
            s[tail++] = s[i];
        }
        return s.substr(start, tail - start);
    }
};
```


