**方法一：使用字符串方法replace()**
```
class Solution {
    /**
    * 思路：
    * 将遍历到的字符用空字符串替换""，
    * 字符串长度只减少一则该字符唯一，否则该字符不唯一。
    */
    public boolean isUnique(String astr) {
        for (int i = 0; i < astr.length(); i++){
            String s = astr;
            s = s.replace(String.valueOf(s.charAt(i)), "");
            if (s.length() != astr.length() - 1)
                return false;
        }
        return true;
    }
}
```

**方法二：使用字符串方法indexOf()**
```
class Solution {
    /**
    * 思路：
    * 字符串方法indexOf(int ch,int start)
    * 返回指定字符从start位置开始到字符串结尾之间出现的第一个位置。
    * 调用方法从遍历到的字符位置加一判断之后是否有重复字符。
    */
    public boolean isUnique(String astr) {
        for(int i = 0; i < astr.length(); i++){
            if(astr.indexOf(astr.charAt(i), i + 1) >= 0){
                return false;
            }
        }
        return true;
    }
}
```

**方法三：双重循环遍历比较**
```
class Solution {
    /**
    * 思路：
    * 双重循环遍历比较是否有相同的字符存在
    */
    public boolean isUnique(String astr) {
        for(int i = 0; i < astr.length() - 1; i++){
            for(int j = i + 1; j < astr.length(); j++){
                if(astr.charAt(i) == astr.charAt(j)){
                    return false;
                }
            }
        }
        return true;
    }
}
```
