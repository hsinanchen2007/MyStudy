经过前面的几次做题，只要是对称的输入，都可以用数字栈。
```
public boolean judgeCircle(String moves) {
        int stock = 0;
        int stock1 = 0;
        for(int i=0;i<moves.length();i++){
            char c = moves.charAt(i);  //返回指定位置索引的字符
            if(c=='U'){
               stock++;
            }
            if(c=='D'){
                stock--;
            }
            if(c=='R'){
                stock1++;
            }
            if(c=='L'){
                stock1--;
            }
        }
        if(stock==0&stock1==0){
                return true;
        }else{
            return false;
        } 
    }
```
