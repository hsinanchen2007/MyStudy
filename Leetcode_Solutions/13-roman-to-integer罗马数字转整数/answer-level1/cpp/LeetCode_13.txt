### 解题思路
此处撰写解题思路:运用栈处理，遍历字符串中每个字符转换成相应的数字压栈，然后通过依次出栈累加（若栈顶元素大于栈顶的下一位元素，则减去栈顶的下一位元素，否则加上该元素）
执行用时 :8 ms, 在所有 C++ 提交中击败了94.34%的用户
内存消耗 :9.7 MB, 在所有 C++ 提交中击败了66.36%的用户

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        int num=0;
        int topnum;
        stack<int> sta;
        for(size_t i=0;i<s.size();++i){     /*遍历字符串，转换成相应的数字压栈*/
            switch (s[i]) {
            case 'I':
                sta.push(1);
                break;
            case 'V':
                sta.push(5);
                break;
            case 'X':
                sta.push(10);
                break;
            case 'L':
                sta.push(50);
                break;
            case 'C':
                sta.push(100);
                break;
            case 'D':
                sta.push(500);
                break;
            case 'M':
                sta.push(1000);
                break;
            default:
                break;
            }
        }
        num=sta.top();  /*num赋值栈顶元素*/
        while (sta.size()!=1) { /*出栈操作，栈大小为1时跳出循环*/
        topnum=sta.top();   /*保存栈顶元素*/
        sta.pop();          /*弹出栈顶元素*/
        if(sta.top()<topnum)/*比较此时栈顶元素与先前的栈顶元素大小，若小则num减去该数*/
            num-=sta.top(); /*若大则num加上该数*/
        else
           num+=sta.top();
        }
        if(num>=1&&num<=3999)
            return num;     /*返回num*/
        else
            return 0;
    }
};
```