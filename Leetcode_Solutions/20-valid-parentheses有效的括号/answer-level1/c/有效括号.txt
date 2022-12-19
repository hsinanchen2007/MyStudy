### 解题思路
很典型的栈问题，现将左括号压入栈，遇到有括号判断是否匹配。
空的情况其实没必要另外考虑，直接跳过while循环，返回还是true
![QQ图片20200330201331.png](https://pic.leetcode-cn.com/0af756bca71a225348b51cda4463dca2d5f51d06ecdd545519f71855e721daf4-QQ%E5%9B%BE%E7%89%8720200330201331.png)

###bug
问题就是新建数组的大小，因为第一次测试显示数组不够大，强行开了10000的空间

### 代码

```c
bool isValid(char * s){
    char stack[100000];
    int i=0,j=0;
    while(s[i]!='\0'){
        if(s[i]=='('||s[i]=='['||s[i]=='{'){
            stack[j++]=s[i];
        }else if(s[i]==')'){
            if(j-1<0||stack[j-1]!='('){
                return false;
            }else{
                j--;
            }
        }else if(s[i]==']'){
            if(j-1<0||stack[j-1]!='['){
                return false;
            }else{
                j--;
            }
        }else if(s[i]=='}'){
            if(j-1<0||stack[j-1]!='{'){
                return false;
            }else{
                j--;
            }
        }
        
        i++;
    }
    return !j;
}
```