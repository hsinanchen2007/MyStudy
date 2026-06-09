### 解题思路

![图片.png](https://pic.leetcode-cn.com/aaad2230ac22f93e0ae59dab645795e9aa0ad116df907633b3464544cabd94ea-%E5%9B%BE%E7%89%87.png)

### 代码

```c
bool isValid(char * s){
    int stack[5000];int top=-1;
    int len=strlen(s);
    for(int i=0;i<len;i++){
        if(top==-1){
            stack[++top]=s[i];
            continue;
        }
        switch(s[i]){
            case ')':if(stack[top]=='('){top--;}else{stack[++top]=s[i];} break;
            case ']':if(stack[top]=='['){top--;}else{stack[++top]=s[i];} break;
            case '}':if(stack[top]=='{'){top--;}else{stack[++top]=s[i];} break;
            default:stack[++top]=s[i];
        }
    }
    if(top!=-1){
        return false;
    }else{
        return true;
    }
}
```