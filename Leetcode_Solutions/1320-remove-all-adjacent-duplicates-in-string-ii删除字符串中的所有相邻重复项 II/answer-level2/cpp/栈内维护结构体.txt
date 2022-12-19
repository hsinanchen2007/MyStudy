### 解题思路
本题还可以用栈来解决，不过栈内维护的是结构体，字母和连续出现次数。当栈顶元素与当前字符串字母不同时，比较栈顶元素中的次数，若次数大于等于k，更新次数。最后将栈内元素依次出栈，得到结果字符串。
### 代码

```cpp
class Solution {
public:
    struct chars  //结构体里为字母及连续出现次数
    {
        char word;
        int num;
    }nodes;
    string removeDuplicates(string s, int k) {
        stack<chars> words;
        int i = 0, len = s.size();
        while(i < len)
        {
            if(words.empty())  //栈为空时，直接入栈
            {
                nodes.word = s[i];
                nodes.num = 1;
                words.push(nodes);
                i ++;          
            }
            else if(words.top().word == s[i])  //当前字母与栈顶元素字母一致时，更新栈顶元素的出现次数
            {
                nodes.word = s[i];
                nodes.num = words.top().num + 1;
                words.pop();
                words.push(nodes);
                i ++;
            }
            else if(words.top().word != s[i])
            {
                if(words.top().num == k)  //当前栈顶元素出现的次数为k时，直接出栈
                words.pop();
                else
                {
                if(words.top().num > k)  //当前栈顶元素出现的次数大于k时，更新
                {
                    nodes.word = words.top().word;
                    nodes.num = words.top().num - k;
                    words.pop();
                    words.push(nodes);
                }
                else  
                {
                nodes.word = s[i];
                nodes.num = 1;
                words.push(nodes);
                i ++; 
                }
                }
            }
        }
        if(words.size() && words.top().num >= k)  //如果字符串最后一个字符出现的次数大于等于k时，上面的循环无法操作，直接退出循环了，要在这里额外判断，我第一次写的时候就忘了，结果有的例子无法通过
        {
            nodes.word = words.top().word;
            nodes.num = words.top().num - k;
            words.pop();
            words.push(nodes);
        }
        string ans;
        while(!words.empty())
        {
            for(int i = 0; i < words.top().num; i ++)
            ans = words.top().word + ans;
            words.pop();
        }
        return ans;
    }
};
```