### 解题思路
用类似栈的解法，遍历字符串，如果是左括号则标记其位置，如果是右括号则与最近记录的左括号相匹配，匹配失败;匹配成功继续下个匹配，直到左括号匹配完，此时还有右括号则失败，否则匹配成功。

### 代码

```c
bool isValid(char * s){
    int count=0,pre[10000],n=0;     //count标记与右括号最近的左括号在数组pre中的位置，pre数组记录左括号在字符串中的位置
    for(int i=0;i<strlen(s);i++){   
        switch(s[i]){
            case '(':pre[count++]=i;break;
            case '{':pre[count++]=i;break;
            case '[':pre[count++]=i;break;
            case ')':if((--count)<0) return false;n=pre[count];if(s[n]!='(')  return false;break;
            case '}':if((--count)<0) return false;n=pre[count];if(s[n]!='{') return false;break;
            case ']':if((--count)<0) return false;n=pre[count];if(s[n]!='[') return false;break;
        }
    }
    if(count==0)
    return true;
    else
    return false;
}
```