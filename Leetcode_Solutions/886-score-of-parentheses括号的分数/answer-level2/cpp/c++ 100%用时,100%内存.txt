### 解题思路
![QQ图片20200316204824.png](https://pic.leetcode-cn.com/b73354e020daba3ffb82128cd1a0660a31f4a1989842df72e485499d44bbd16a-QQ%E5%9B%BE%E7%89%8720200316204824.png)
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int scoreOfParentheses(string S) {
        int result=0,value=1,size=S.size(),count=0;
        char tmp;
        for(int i=0;i<size;i++){
            tmp=S[i];
            if(tmp=='('){
                count++;
            }else{
                result+=value<<(count-1);
                count--;
                while(S[++i]==')'){
                    count--;
                }
                i--;
            }
        }
        return result;
    }
};
```