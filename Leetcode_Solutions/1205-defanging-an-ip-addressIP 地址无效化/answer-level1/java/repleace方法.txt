replace方法（搬运介绍）
    该方法的作用是替换字符串中所有指定的字符，然后生成一个新的字符串。经过该方法调用以后，原来的字符串不发生改变。例如：

    String s = “abcat”；

    String s1 = s.replace（‘a’，‘1’）；

    该代码的作用是将字符串s中所有的字符a替换成字符1，生成的新字符串s1的值是“1bc1t”，而字符串s的内容不发生改变。

    如果需要将字符串中某个指定的字符串替换为其它字符串，则可以使用replaceAll方法，例如：

    String s = “abatbac”；

    String s1 = s.replaceAll（“ba”，“12”）；

    该代码的作用是将字符串s中所有的字符串“ab”替换为“12”，生成新的字符串“a12t12c”，而字符串s的内容也不发生改变。

    如果只需要替换第一个出现的指定字符串时，可以使用replaceFirst方法，例如：

    String s = “abatbac”；

    String s1 = s. replaceFirst （“ba”，“12”）；

    该代码的作用是只将字符串s中第一次出现的字符串“ab”替换为字符串“12”，则字符串s1的值是“a12tbac”，字符串s的内容也不发生改变。


代码如下：
class Solution {
    public String defangIPaddr(String address) {
        String ad1 = address.replace(".","[.]");
        return ad1;
    }
}