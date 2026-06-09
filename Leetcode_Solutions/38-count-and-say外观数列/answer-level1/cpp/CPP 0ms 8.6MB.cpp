### 解题思路
报数n=1就返回"1"
报数n>1就循环n-1次：
每次循环就是对上一次报数结果进行报数
循环中遍历string的每一个字符
    如果与上一个字符不同：新结果的最后加上'1'和当前字符
    如果与上一个字符相同：将新结果的倒数第二个字符的值+1

### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
        string res="1";
        if(n==1){
            return res;
        }else{
            for(int i=0;i<n-1;i++){
                string temp="";
                char last='0';
                for(char x:res){
                    if(x==last){
                        temp[temp.length()-2]+=1;
                    }else{
                        last=x;
                        temp+='1';
                        temp+=x;
                    }
                }
                res=temp;
            }
        }
        return res;
    }
};
```