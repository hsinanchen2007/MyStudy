![image.png](https://pic.leetcode-cn.com/8dfa6c7f8807ba5277623bdbbe833a3ad111bc504e480dd14b4774647863d19f-image.png)

栈中栈，但是并不知道怎么降低内存占用
```c++
//
//  No 394.cpp
//
//  维持四个栈：
//  1、string的栈的栈，作为最外层栈，2、以及其中每个string的栈用来匹配两个括号间字符
//  3、一个int的栈multiple，每个括号的string栈对应的int栈中的一个元素，用来储存每个括号里的字符串的重复次数
//  4、构建重复次数的栈mul_cache，用来将字符转化为数字

#include<string>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<char> mul_cache;
        stack<int> multiple;
        stack<stack<string> > mainstack;
        stack<string> first; // 这里是否可以改进？
        mainstack.push(first);
        for (int i=0; i<s.size(); i++){
            if (s[i]-'0'<10) mul_cache.push(s[i]); // 数字放入一个单独的构建栈
            else if (s[i] == '[') {
                // 这里完成两件事，一是输出[前面的数字到multiple
                string multiple_times;
                while(!mul_cache.empty()){
                    multiple_times += mul_cache.top();
                    mul_cache.pop();
                }
                reverse(multiple_times.begin(),multiple_times.end());
                int mul = stoi(multiple_times);
                multiple.push(mul);
                // 二是为[到下一个数字之间的字符创一个新栈并存入mainstack顶端
                stack<string> newstack;
                mainstack.push(newstack);
            }
            else if (s[i]==']'){
                // 这里要完成件两件事
                // 这里终结charaters顶部中的最后一个栈，输出为string
                // 重复multiple顶部数字次数，multiple顶部数字出栈，将结果输出到前一个string栈中
                stack<string> top_string = mainstack.top();
                mainstack.pop();
                string cache;
                while(!top_string.empty()){
                    cache += top_string.top();
                    top_string.pop();
                }
                // reverse(cache.begin(),cache.end()); 不用reverse，要保证builder中全部是颠倒的
                int mul_times = multiple.top();
                multiple.pop();
                string builder;
                for (int i=0;i<mul_times;i++)
                    builder += cache;
                mainstack.top().push(builder);
            }
            else{
                string newstring{s[i]}; // 这里初始化好像不能用拷贝初始化和小括号直接初始化
                mainstack.top().push(newstring); // 放到characters栈顶的栈的顶部
            }
        }
        
        // 这里mainstack中应该仅剩一个stack
        stack<string> builder_cache = mainstack.top();
        mainstack.pop();
        string builder;
        while(!builder_cache.empty()){
            builder += builder_cache.top();
            builder_cache.pop();
        }
        reverse(builder.begin(),builder.end());
        
        return builder;
    }
};
```

