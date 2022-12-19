### 解题思路
此处撰写解题思路
理解题意 “不是字母的字符都保留在原地” 
### 代码

```cpp
class Solution {
public:
    string reverseOnlyLetters(string S) {
      int first = 0;
      int second = 0;
      string result = S;
      for (int i = 0; i < S.length(); i++) {
          if ((S[i] <= 'z' && S[i] >= 'a') 
            || (S[i] <= 'Z' && S[i] >= 'A') )  {
            //cout << S[i] << endl;
            charStack.push(S[i]);
          }
      }
      
      int index = 0;
      while (!charStack.empty()) {
          char temp = charStack.top();
          if ((result[index] <= 'z' && result[index] >= 'a') 
            || (result[index] <= 'Z' && result[index] >= 'A')) {
            result[index] = temp;
            charStack.pop();
          }
          
          index++;
      }

      return result;
    }
private:
    stack<char> charStack;
};
```