### 目录

题目目录: [Leetcode 题解 - 双指针](https://github.com/CyC2018/CS-Notes/blob/master/notes/Leetcode%20%E9%A2%98%E8%A7%A3%20-%20%E5%8F%8C%E6%8C%87%E9%92%88.md)

### 题目
给定一个字符串和一个字符串字典，找到字典里面最长的字符串，该字符串可以通过删除给定字符串的某些字符来得到。如果答案不止一个，返回长度最长且字典顺序最小的字符串。如果答案不存在，则返回空字符串。

示例 1:

    输入:
    s = "abpcplea", d = ["ale","apple","monkey","plea"]

输出: 

    "apple"

示例 2:

    输入:
    s = "abpcplea", d = ["a","b","c"]

输出: 
    "a"
说明:

    所有输入的字符串只包含小写字母。
    字典的大小不会超过 1000。
    所有输入的字符串长度不会超过 1000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting
### 解题思路
- "字符串可以通过删除给定字符串的某些字符来得到",这句话的意思是: 找的这个是给定字符串的子串,相同字符的
顺序相等
- "如果答案不止一个，返回长度最长且字典顺序最小的字符串",如果找的的字符串长度想等,需要比较字典顺序,用
compareTo()方法,(这玩意有歧义,给定字符串它也叫'字典').
- 由上两个条件,咱们是不是可以考虑先对字符串进行条件判断.先排除不符合条件的
- 接下来对符合条件的字符串进行比对: 
    采用双指针:遍历给定字符串,因为找的是子集,与字典中的字符串一个个比.如果相等,它俩下标都加一,再判断
    字典中的字符串是否和下标相等了,如果相等,证明找到了.


### 代码

```java
class Solution {
    public String findLongestWord(String s, List<String> d) {
        char[] sc = s.toCharArray();
        String result = "";
        for(String ds : d){
            // 先对长度进行判断,(如果小于结果字符串,不用比了 || (如果相等 && 字典顺序小 也不用比了))
            if(result.length() > ds.length() || (result.length() == ds.length() && result.compareTo(ds) < 0)){
                continue;
            }

            if(isSubStr(sc,ds)){
                result = ds;
            }
        }
        return result;
    }
    public boolean isSubStr(char[] sc,String ds){
        // 字典字符串下标
        int i = 0;
        char[] dsc = ds.toCharArray();
        for(char s : sc){
            if(s == dsc[i]){
                i ++;
                // 如果下标和长度相等,就证明找到了
                if(i == dsc.length){
                    return true;
                }
            }
        }
        // 这还找不到,就证明失败了
        return false;
    }
}
```