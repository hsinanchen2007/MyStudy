### 解题思路
两次反转

删除字符串多余空格参考[原地两次翻转/栈存储_面试题58 - I. 翻转单词顺序](https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof/solution/yuan-di-liang-ci-fan-zhuan-zhan-cun-chu-_mian-shi-/)


### 代码

```cpp
class Solution{
public:
    string reverseWords(string s) {
        if(s.empty()) return s;

        // 反转整个句子
        myReverse(s.begin(), s.end());
        // cout << "s after reverse is " << endl << s << endl;
        s.erase(0, s.find_first_not_of(' '));
        s.erase(s.find_last_not_of(' ') + 1);

            // 删除字符串单词间的多余1的空格
    // 定义快慢指针
    int fast = 1, slow = 0;
    while (slow < s.length()) {
        // 当慢指针和快指针同时指向空字符时
        if (s[slow] == ' ' && s[fast] == ' ') {
            // 如果有多于2的空字符，
            // 就将快指针继续后移，一直到不是空字符为止
            while (s[fast] == ' ') {
                fast++;
            }

            // 因为此时fast指向非空字符，
            // 则删掉除slow指向的空字符外的其它空字符
            // 删掉的空字符数为： fast - slow - 1
            s.erase(slow, fast - slow - 1);

            // slow指向空格，fast继续指向slow后面
            fast = slow + 1;
        } else {
            slow++;
            fast++;
        }
    }


        // 反转句子中的单词
        string::iterator sBegin = s.begin();
        string::iterator sEnd = s.begin();
        while (sBegin != s.end())
        {
            /* 遍历整个string */
            if(*sBegin == ' '){
                // 如果sBegin遇到空格就跳过
                sBegin++;
                sEnd++;
            }
            else if (*sEnd == ' ')
            {
                // cout << "sEnd is " << *sEnd << endl;
                /* sEnd为空格或者为end说明到达单词尾部，可以进行反转了 */
                myReverse(sBegin, sEnd);
                
                // cout << s << endl;
                sBegin = ++sEnd;    // sBegin指向下一个单词首部
                // cout << "sBegin is " << *sBegin << endl;
            }
            else if(sEnd == s.end()){
                myReverse(sBegin, sEnd);
                break;
            }
            else
            {
                sEnd++;
            } 
        }      
        return s;
    }

    template <class BidirectionalIterator>
    void myReverse(BidirectionalIterator first, BidirectionalIterator last){
        while((first != last) && (first != --last)){
            std::iter_swap(first, last);
            ++first;
        }
    }
};
```