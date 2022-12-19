### 解题思路
来自一个老实人的解析！

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {

       int left = 0;
       int right = s.size()-1;
       string s0 = "";
       string temp = "";
       bool add = false;
       while(left<right){

          char t = s[right];
          s[right] = s[left];
          s[left] = t;
          left++;
          right--;
       }

       for(int i = 0;i<s.size();i++){

           if(s[i] == ' '&&temp == ""){
               continue;
           }

           if(s[i] != ' '){
               if(add == true){
                   s0 += ' ';
                   add = false;
               }
               temp = s[i] + temp; 
           }
           else{
              s0 += temp;
              add = true;
              temp = "";
           }

           if(i == s.size()-1){
               s0 += temp;
           }
       }

       return s0;
    }
};
```