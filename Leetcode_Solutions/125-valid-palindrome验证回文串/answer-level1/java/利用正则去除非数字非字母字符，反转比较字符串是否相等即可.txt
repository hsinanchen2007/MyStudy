我想到的最简单的方法是通过正则过滤非字母非数字字符，通过反转比较是否相等，进行判断是否满足回文字符串要求。
```java []
    public boolean isPalindrome(String s) {
        // 只留下数字和字母
        StringBuffer buffer = new StringBuffer(s.replaceAll("[^0-9a-zA-Z]","").toLowerCase());
        if(buffer.toString().equals(buffer.reverse().toString())){
            return true;
        }
        return false;
    }
```
