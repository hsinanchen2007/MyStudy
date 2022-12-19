### 解题思路
![屏幕截图(18).png](https://pic.leetcode-cn.com/29b61c484d6d93c09f8687f4ada94c37e76036d8c0e394ae192014e6322a0c36-%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE\(18\).png)

读完题意，我们知道我们要尽量使字符串是AB型的，而非(A)型：
AB：()()() (A)型:((()))
所以：
用两个变量计字符串A,B的左括号数。
 1.当目前读到左括号时，理所应当往A，B中左括号少的插。
 2.当目前读到右括号时，理所应当往两者中左括号多的插。

### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        if(seq.empty()) return {};
        int a = 0,b = 0;
        vector<int> ans(seq.size());
        for(int i = 0;i < seq.size();i++){
            if(seq[i] == '('){
                if(a > b){
                    ans[i] = 1; b++; 
                }
                else{
                    ans[i] = 0; a++;
                }
            }
            else{
                if(a > b){
                    a--; ans[i] = 0;
                }
                else{
                    b--; ans[i] = 1;
                }
            }
        }

        return ans;
    }
};
```