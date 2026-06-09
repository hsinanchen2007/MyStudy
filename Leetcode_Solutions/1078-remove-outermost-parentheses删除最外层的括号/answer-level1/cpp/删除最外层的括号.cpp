### 解题思路
这题类似1221分割平衡字符串的做法

### 代码

```cpp
class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        stringstream ss;
        int left=0, right=0;
        int start=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                left++;
            }else{
                right++;
            }//if

            if(left==right){
                for(int j=start+1;j<i;j++){
                    ss<<s[j];
                }
                start=i+1;
                left=0;
                right=0;
            }//if

        }
        ss>>res;
        return res;
    }
};
```