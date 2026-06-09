看结果可知，必须R出现的次数和L出现的次数相等，才满足条件
因此可以遍历字符串，记录R出现的次数和L出现的次数，如果相等让标记为+1

```
public int balancedStringSplit(String s) {
        int R = 0;
        int L = 0;
        int flag = 0;
        for(int i=0;i<s.length();i++){
            char c = s.charAt(i); //返回指定索引处的字符
            if(c=='R'){
                R++;
            }else{
                L--;
            }
            if(R+L == 0){
                flag++;
            }
        }
        return flag;
    }
```

做完之后，看了别人的题解，用数字栈更优秀，stack相当于一个栈，当等于R栈长度+1，等于L栈长度-1，如果栈长度为0标记位+1，可以省去一个变量。