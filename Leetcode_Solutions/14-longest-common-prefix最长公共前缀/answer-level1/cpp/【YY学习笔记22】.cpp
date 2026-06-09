### 解题思路
双重循环求解：**外层：**只要有相同的字符，就继续，直到碰见第一个不相同的。**内层：**比较第num个字符是否相同
### 感悟
还是不周全：做题时考虑到了部分为空的情况["","aaa","abc"]，考虑到了普通情况，却忽视了全空的情况[],以及只有一个字符串的情况["aaa"]。
### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int num=0;//0-num的字符都是相等的。
        int length=strs.size();
        bool again=true;

        if(length==0) return "";//错误点1：没有考虑[]。
        if(length==1) return strs[0];//错误点2:没有考虑容器中只有一个字符串的情况。
        while(again){
        //比较第num个字符是否相等。
        
        for(int i=0;i<length-1;++i){
            if(strs[i][num]!=strs[i+1][num]||num>=strs[i].length()||num>=strs[i+1].length()){
                again=false;
                break;
            }
        }
        if(again)
        num++;
        }

        num--;
        string result;
        for(int i=0;i<=num;i++){
            result.push_back(strs[0][i]);
        }
        if(num<0) return "";
        return result;
    }
};
```