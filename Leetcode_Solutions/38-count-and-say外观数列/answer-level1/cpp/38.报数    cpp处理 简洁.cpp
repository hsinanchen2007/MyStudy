### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
    //Mine>>L
public:
    string countAndSay(int n) {
        string str="1";
        while(--n){//从1开始，数清总步数
            string ans;
            str+='#';//借助#占最后一位
            int cnt=1;
            for(int i=1;i<str.length();i++){
                if(str[i]==str[i-1]){
                    cnt++;
                }else{//位于最后的#不可能和数字相等，对前者进行统计并且不计算#
                    ans+=to_string(cnt)+str[i-1];
                    cnt=1;
                }
            }
            str=ans;//值传递
        }
        return str;
    }
};
```