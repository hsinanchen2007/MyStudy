## 1、公共前缀追加（类似官方方法2）

暴破是一定可以做的，用首个字符串的第一个字符开始，逐个去比较是公共的就追加上去。当第m个字符不是公共时，则返回之前的部分。很容易想到，时间复杂度O(m*n).

代码：

```java
public String longestCommonPrefix(String[] strs) {
    StringBuilder cp = new StringBuilder();
    cp.append("");

    if (strs.length == 0) return cp.toString();

    int index=0;
    while (cp.length() < strs[0].length()){
        String temp = strs[0].substring(index,index+1);
        for (String ele: strs){
            if (cp.length()==ele.length()||!ele.substring(index,index+1).equals(temp))
                return cp.toString();
        }
        cp.append(temp);
        index++;
    }
    return cp.toString();
}
```



- ## 2、公共前缀裁剪（官方题解方法1）

与第一种解法相反，直接将首个字符串拿去与每个字符相比，裁剪掉不同的部分。时间复杂度最坏也是O(m*n)，但是多数情况下与第2个字符串相比时，就可以裁剪掉非公共前缀的大部分字符。

注意这里使用的strs [i].indexOf(prefix)方法，当str中不能完整匹配prefix时这里返回-1，而完全匹配时返回首个匹配字符的下标，又是前缀所以会返回0。反之，当一直不返回0时则没有前缀匹配上就继续裁剪prefix.


代码：

```java
public String longestCommonPrefix(String[] strs){
    if (strs.length==0) return "";
    String prefix = strs[0];
    for (int i =1; i <strs.length; i++){
        while (strs [i].indexOf(prefix) !=0){
            prefix=prefix.substring(0,prefix.length() -1);
            if (prefix.isEmpty()) return "";
        }
    }
    return prefix;
}
```

