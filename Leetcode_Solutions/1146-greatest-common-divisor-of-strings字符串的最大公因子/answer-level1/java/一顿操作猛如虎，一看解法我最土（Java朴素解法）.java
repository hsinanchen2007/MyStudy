睡前，我打开了今天的每日一题，看着绿绿的 “简单” 标签，我微微一笑 —— 搞它！

看懂题目后，我陷入了沉思，没什么思路啊！就这？还是简单题？

长时间的自我怀疑之后，我看到了题目 《字符串的最大公因子》。嗯，最大公因子？辗转相除？不怎么灵活的小脑瓜突然一动：

- 如果二者存在最大公因子，那，不就和求两个数字的最大公因数相似吗？
- **那么，只需要求出两个字符串长度的最大公因数，然后返回相同长度的字串（从字符串起始位置开始）不就行了。**
- 所以啊，我将不存在公因数的字符串给筛出来之后，直接用辗转相除法不就行了吗？

说搞就搞，一顿操作之后，我写出了代码：(有点小问题，但是 `20-2-12` 可以提交通过)

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        // 筛选出不存在公约数的样例
        int len1 = str1.length(), len2 = str2.length();
        boolean flag = (len1 > len2) ? isPresence(str1, str2):isPresence(str2, str1);
        if (!flag)  return "";
        
        // 存在，则直接求解
        int count = gcd(len1, len2);
        String ret = str1.substring(0, count);
        return ret;
    }
    
    private boolean isPresence(String str1, String str2) {
        // 判断是否存在公约数：即包含的元素一致，且顺序对得上
        if (str1.indexOf(str2) == -1)    return false;
        for (char c:str1.toCharArray()) {
            if (str2.indexOf(c) == -1)  return false;
        }
        return true;
    }
    
    private int gcd(int a, int b) {
        // 求两数的最大公约数
        if (a % b == 0) return b;
        else   return gcd(b, a%b);
    }
}
```

提交！`2ms`？并没有打败 `100%` ？

什么嘛！让俺康康提交结果。什么？还有 `0ms` 的？

怀着求知的心情点开了示例代码，盯了许久之后，不由叹息，菜鸡始终是菜鸡啊！嗯？怎么快两点了？睡了睡了！

---

经评论[@wo-zhe-yi-tou-xiao-bai-zhu](/u/wo-zhe-yi-tou-xiao-bai-zhu/) 提醒，我发现 `["ABCABC", "BCA"]` 这样的样例会`WA`掉，不过官方好像没有这样的样例。。。

所以改了下：（还是有问题，查看最新版请往下拉！）

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        int len1 = str1.length(), len2 = str2.length();
        boolean flag = (len1 > len2) ? isPresence(str1, str2):isPresence(str2, str1);
        if (!flag)  return "";
        
        // 求len1 和 len2 的最小公约数
        int count = gcd(len1, len2);
        String ret = str1.substring(0, count);
        return ret;
    }
    
    private boolean isPresence(String str1, String str2) {
        // 包含的元素一致，且顺序对得上
        for (int i = 0; i < str2.length(); i++) {
            if (str1.charAt(i) != str2.charAt(i))   return false;
        }
        
        for (int i = str2.length(); i < str1.length(); i++) {
            char c = str1.charAt(i);
            if (str2.indexOf(c) == -1)  return false;
        }
        return true;
    }
    
    private int gcd(int a, int b) {
        if (a % b == 0) return b;
        else   return gcd(b, a%b);
    }
}
```

但是运行时间变成了 `3ms`。。。

---

哎呀！还是有问题，自己的小脑瓜果然不怎么灵活呢！多谢 [@chen-mo-fei-wu-yan-zhu](/u/chen-mo-fei-wu-yan-zhu/) 提醒 `["ABCAAA" 和 `ABC`]` 又能将俺的两个代码搞崩，那继续修改咯！

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        int len1 = str1.length(), len2 = str2.length();
        boolean flag = (len1 > len2) ? isPresence(str1, str2):isPresence(str2, str1);
        if (!flag)  return "";
        
        // 求len1 和 len2 的最小公约数
        int count = gcd(len1, len2);
        String ret = str1.substring(0, count);
        return ret;
    }
    
    private boolean isPresence(String str1, String str2) {
        int len = str2.length();
        // 包含的元素一致，且顺序对得上
        for (int i = 0; i < str1.length(); i++) {
            if (str1.charAt(i) != str2.charAt(i%len))   return false;
        }
        
        return true;
    }
    
    private int gcd(int a, int b) {
        if (a % b == 0) return b;
        else   return gcd(b, a%b);
    }
}
```

这下行了吧，还是 `3ms`，希望大家继续指出错漏啊！
