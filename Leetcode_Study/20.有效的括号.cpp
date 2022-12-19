/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

/*

https://leetcode.cn/problems/valid-parentheses/

20. 有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
 

示例 1：

输入：s = "()"
输出：true

示例 2：

输入：s = "()[]{}"
输出：true

示例 3：

输入：s = "(]"
输出：false

示例 4：

输入：s = "([)]"
输出：false

示例 5：

输入：s = "{[]}"
输出：true
 

提示：

1 <= s.length <= 104
s 仅由括号 '()[]{}' 组成
通过次数1,171,483提交次数2,625,190

*/

// @lc code=start
class Solution100 {
public:
    // 2022.7.24, by Hsinan. Need to ensure two tricky parts
    //   1. Before top()/pop(), make sure the stack is not empty
    //   2. At the end, ensure the stack is empty, otherwise they are some mismatched items left
    bool isValid(string s) {
        // sanity check
        if (s.empty()) return true;

        // only one, not even a pair, always false
        if (s.size() == 1) return false;

        // stack container to perform the check comparision
        std::stack<char> match;

        for (char c : s) {
            if (c == '{' || c == '[' || c == '(') {
                match.push(c);
                continue;
            } else {
                // as we are sure the given characters should be only {}[]()
                // so if here and stack is already empty, return false
                if (match.size() == 0) return false;

                // now if they are }, ], ), try to pop item from match and see if they are matched
                if (c == '}') {
                    char test = match.top();
                    match.pop();
                    if (test != '{') {
                        return false;
                    } else {
                        continue;
                    }        
                }
                if (c == ']') {
                    char test = match.top();
                    match.pop();
                    if (test != '[') {
                        return false;
                    } else {
                        continue;
                    }
                }
                if (c == ')') {
                    char test = match.top();
                    match.pop();
                    if (test != '(') {
                        return false;
                    } else {
                        continue;
                    }
                }
            }
        }

        // if stack match is not empty, that means there are some mismatched items left
        return ((match.size() == 0) ? true : false);
    }
};


class Solution99 {
public:
    // 2022.7.24, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0020.%E6%9C%89%E6%95%88%E7%9A%84%E6%8B%AC%E5%8F%B7.md
    /*
       括号匹配是使用栈解决的经典问题。
       
       题意其实就像我们在写代码的过程中，要求括号的顺序是一样的，有左括号，相应的位置必须要有右括号。
       如果还记得编译原理的话，编译器在 词法分析的过程中处理括号、花括号等这个符号的逻辑，也是使用了栈这种数据结构。
       
       再举个例子，linux系统中，cd这个进入目录的命令我们应该再熟悉不过了。
       
       cd a/b/c/../../
       这个命令最后进入a目录，系统是如何知道进入了a目录呢 ，这就是栈的应用（其实可以出一道相应的面试题了）
      
       所以栈在计算机领域中应用是非常广泛的。
      
       有的同学经常会想学的这些数据结构有什么用，也开发不了什么软件，大多数同学说的软件应该都是可视化的软件例如APP、网站之类的，
       那都是非常上层的应用了，底层很多功能的实现都是基础的数据结构和算法。
       
       所以数据结构与算法的应用往往隐藏在我们看不到的地方！
      
       这里我就不过多展开了，先来看题。
       
       进入正题
       由于栈结构的特殊性，非常适合做对称匹配类的题目。
      
       首先要弄清楚，字符串里的括号不匹配有几种情况。
       
       一些同学，在面试中看到这种题目上来就开始写代码，然后就越写越乱。
       
       建议要写代码之前要分析好有哪几种不匹配的情况，如果不动手之前分析好，写出的代码也会有很多问题。
       
       先来分析一下 这里有三种不匹配的情况，
       
       第一种情况，字符串里左方向的括号多余了 ，所以不匹配。 括号匹配1
       第二种情况，括号没有多余，但是 括号的类型没有匹配上。 括号匹配2
       第三种情况，字符串里右方向的括号多余了，所以不匹配。 括号匹配3
       我们的代码只要覆盖了这三种不匹配的情况，就不会出问题，可以看出 动手之前分析好题目的重要性。
      
       动画如下：
      
       20.有效括号
       
       第一种情况：已经遍历完了字符串，但是栈不为空，说明有相应的左括号没有右括号来匹配，所以return false
      
       第二种情况：遍历字符串匹配的过程中，发现栈里没有要匹配的字符。所以return false
       
       第三种情况：遍历字符串匹配的过程中，栈已经为空了，没有匹配的字符了，说明右括号没有找到对应的左括号return false
       
       那么什么时候说明左括号和右括号全都匹配了呢，就是字符串遍历完之后，栈是空的，就说明全都匹配了。
       
       分析完之后，代码其实就比较好写了，
       
       但还有一些技巧，在匹配左括号的时候，右括号先入栈，就只需要比较当前元素和栈顶相不相等就可以了，比左括号先入栈
       代码实现要简单的多了！
    */
    //
    bool isValid(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(')');
            else if (s[i] == '{') st.push('}');
            else if (s[i] == '[') st.push(']');
            // 第三种情况：遍历字符串匹配的过程中，栈已经为空了，没有匹配的字符了，说明右括号没有找到对应的左括号 return false
            // 第二种情况：遍历字符串匹配的过程中，发现栈里没有我们要匹配的字符。所以return false
            else if (st.empty() || st.top() != s[i]) return false;
            else st.pop(); // st.top() 与 s[i]相等，栈弹出元素
        }
        // 第一种情况：此时我们已经遍历完了字符串，但是栈不为空，说明有相应的左括号没有右括号来匹配，所以return false，
        // 否则就return true
        return st.empty();
    }
};


class Solution98 {
public:
    // 2022.7.24, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/valid-parentheses.cpp
    // Time:  O(n)		
    // Space: O(n)
    bool isValid(string s) {
        const  unordered_map<char, char> symbol_pair = {{')', '('},
                                                        {']', '['},
                                                        {'}', '{'}};
        stack<char> parentheses;
        for (const auto& c: s) {
            const auto& it = symbol_pair.find(c);
            if (it != symbol_pair.cend()) {
                if (parentheses.empty() ||
                    parentheses.top() != it->second) {
                    return false;
                }
                parentheses.pop();
            } else {
                parentheses.emplace(c);
            }
        }
        return parentheses.empty();
    }
};


class Solution97 {
public:
    // 登录 AlgoMooc 官网获取更多算法图解
    // https://www.algomooc.com
    // 作者：程序员吴师兄
    // 代码有看不懂的地方一定要私聊咨询吴师兄呀
    // 有效的括号（ LeetCode 20 ）:https://leetcode-cn.com/problems/valid-parentheses
    bool isValid(string s) {
        // 当字符串长度为奇数的时候，属于无效情况，直接返回 false
        if (s.size() % 2 == 1) {
             // 无效情况，返回 false
             return false;
        }
       
        //构建一个栈，用来存储括号
        stack<char> stk ;
        
        // 遍历字符串数组中的所有元素
        for( int i = 0 ; i < s.size() ; i++){
            
            // 获取此时的字符
            char c = s[i];   
            
            // 如果字符为左括号 ( ，那么就在栈中添加对左括号 （
            if(c == '('){
               
               // 添加对左括号 （
               stk.push('(');

             // 如果字符为左括号 [ ，那么就在栈中添加对左括号 [
            }else if(c == '['){

               // 添加对应的右括号 ]
               stk.push('[');

             // 如果字符为左括号 { ，那么就在栈中添加对左括号 {
            }else if( c == '{'){

               // 添加对应的右括号 }
               stk.push('{');

               // 否则的话，说明此时 c 是 ）] } 这三种符号中的一种
            }else {
               
               // 如果栈已经为空，而现在遍历的字符 c 是 ）] } 这三种符号中的一种
               // 找不到可以匹配的括号，返回 false
               // 比如这种情况  }{，直接从右括号开始，此时栈为空
               if(stk.empty()) return false;
               
               // 如果栈不为空，获取栈顶元素
               char top = stk.top();

               // 将栈顶元素和此时的元素 c 进行比较，如果相同，则将栈顶元素移除
               if( top == '(' && c == ')' || top == '[' && c == ']' || top == '{' && c == '}' ){
                   // 移除栈顶元素
                   stk.pop();
               }else{
                   // 如果不相同，说明不匹配，返回 false
                   return false;
               }
 
            }

        }
        
        // 遍历完整个字符数组，判断栈是否为空
        // 如果栈为空，说明字符数组中的所有括号都是闭合的
        // 如果栈为空，说明有未闭合的括号
        return stk.empty();

    }
};


class Solution96 {
public:
    // 2022.7.24, from AcWing
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/346874/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    bool isValid(string s) {
        stack<char> stk;

        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{') stk.push(c);
            else {
                if (stk.size() && abs(stk.top() - c) <= 2) stk.pop();
                else return false;
            }
        }

        return stk.empty();
    }
};


class Solution95 {
public:
    // 2022.7.28, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/20.%20Valid%20Parentheses
    // OJ: https://leetcode.com/problems/valid-parentheses/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(N)
    bool isValid(string s) {
        stack<char> stk;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') stk.push(c);
            else if (stk.empty() || (c == ')' && stk.top() != '(') || (c == '}' && stk.top() != '{')
                || (c == ']' && stk.top() != '[')) return false;
            else stk.pop();
        }
        return stk.empty();
    }
};


class Solution94 {
public:
    // 2022.7.28, from https://walkccc.me/LeetCode/problems/0020/
    // Time: O(n)
    // Space: O(n)
    bool isValid(string s) {
        stack<char> stack;

        for (const char c : s)
        if (c == '(')
            stack.push(')');
        else if (c == '{')
            stack.push('}');
        else if (c == '[')
            stack.push(']');
        else if (stack.empty() || pop(stack) != c)
            return false;

        return stack.empty();
    }

private:
    int pop(stack<char>& stack) {
        const int c = stack.top();
        stack.pop();
        return c;
    }
};


class Solution93 {
public:
    // 2022.7.28, from https://www.guozet.me/leetcode/Leetcode-20-Valid-Parentheses.html?h=isvalid
    /*
        验证输入的字符串是否为括号字符串，包括大括号，中括号和小括号。在这里使用一个栈来实现, 如果扫描到的是左边的括号
        (,{,[, 那么就把其压入到栈中，之后如果扫描到的不是左边的符号的话，那么就把堆栈最上面的数据出栈，然后如果出栈的
        数据是对应的右括号的话，那么就pop 出栈这个数据，如果不是对应的有括号，那么就返回false.
    */
    bool isValid(string s) {
        std::stack<char> parentheses;
        for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            parentheses.push(s[i]);
        else {
            if (parentheses.empty()) return false;
            if (s[i] == ')' && parentheses.top() != '(') return false;
            if (s[i] == '}' && parentheses.top() != '{') return false;
            if (s[i] == ']' && parentheses.top() != '[') return false;
            parentheses.pop();
        }
        }
        return parentheses.empty();
    }
};


class Solution {
public:
    // 2022.7.28, from https://github.com/grandyang/leetcode/issues/20
    /*
        这道题让我们验证输入的字符串是否为括号字符串，包括大括号，中括号和小括号。这里需要用一个栈，开始遍历输入字符串，
        如果当前字符为左半边括号时，则将其压入栈中，如果遇到右半边括号时，若此时栈为空，则直接返回 false，如不为空，则
        取出栈顶元素，若为对应的左半边括号，则继续循环，反之返回 false，代码如下：
    */
    bool isValid(string s) {
        stack<char> parentheses;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') parentheses.push(s[i]);
            else {
                if (parentheses.empty()) return false;
                if (s[i] == ')' && parentheses.top() != '(') return false;
                if (s[i] == ']' && parentheses.top() != '[') return false;
                if (s[i] == '}' && parentheses.top() != '{') return false;
                parentheses.pop();
            }
        }
        return parentheses.empty();
    }
}; 


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

