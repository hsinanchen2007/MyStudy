**思路：** 定义一个上下方向ud的变量，初始为0，向上走加一，向下走减一。定义一个左右方向的lr的变量，初始
为0，向左走减一，向右走加一。最后的执行全部的路径这两个点还是初始值，可知机器人返回了原点。
```java []
public boolean judgeCircle(String moves) {
        int ud = 0;
        int lr = 0;
        for (char c:moves.toCharArray()){
            if(c=='R')lr++;
            if(c=='L')lr--;
            if(c=='U')ud++;
            if(c=='D')ud--;
        }
        if(ud==0&&lr==0)return true;
        return false;
    }
```

