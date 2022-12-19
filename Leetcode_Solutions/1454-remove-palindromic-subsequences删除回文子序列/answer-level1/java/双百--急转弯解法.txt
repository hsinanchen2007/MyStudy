![image.png](https://pic.leetcode-cn.com/c35262b067c0e95a0e2d5d9297d17bdcb656d9bac46dfa73d239f09b711f8378-image.png)

第一印象（被示例1忽悠了）：每次寻找最大的回文子串，删除继续递归寻找。--这很明显不是简单题的做法

正确姿势：每次删除一种回文串又不是一个。。。。所以可以第一步全部删除“a”，第二次“b”...也就是不超过2次！！！！！



```
    public int removePalindromeSub(String s) {
       
        int result=0;
        if (s.contains("a"))
            result++;
        if (s.contains("b"))
            result++;
        StringBuffer stringBuffer=new StringBuffer(s);
        stringBuffer.reverse();
        if (s.equals(stringBuffer.toString())&&stringBuffer.length()>0)
            return 1;
        return result;
        
    }
```
