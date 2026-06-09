### 解题思路
总的思路分为三步
一：解析目标字符串得到对应的字符串数组；
二：再先存入第一组字符串的子集到结果集；
三：遍历剩余字符串，递归拼接得到最新的结果集。
### 代码
![image.png](https://pic.leetcode-cn.com/473fe438c046c132ec61ac8dd42fc8765043ca1e351b1fc9a200e7d72d174538-image.png)

```java
class Solution {
    public static List<String> letterCombinations(String digits) {
        List<String> result = new ArrayList<>();
        char[] ds = digits.toCharArray();
        String[] st = new String[ds.length];
        for (int i = 0; i < ds.length; i++) {
            st[i] = getStr((ds[i]-'0')+"");
        }
        //排除获取为 ""
        if(st.length > 0){
            //先存入第一组字符串
            for (char cs:st[0].toCharArray()) {
                result.add(cs+"");
            }
            //再递归拼接后面每一组字符串
            for (int i = 1; i < st.length; i++) {
                result = getStr(result,st[i]);
            }
        }
        return result;
    }

    //递归拼接字符串，遍历源字符串 + 拼接后一个字符串的子集
    private static List<String> getStr(List<String> re,String str){
        List<String> results = new ArrayList<>();
        for (String s:re) {
            for (char c:str.toCharArray()) {
                results.add(s+c);
            }
        }
        return results;
    }

    //获取常量
    private static String getStr(String str){
        String re = "";
        switch (str){
            case "2":re = "abc";break;
            case "3":re = "def";break;
            case "4":re = "ghi";break;
            case "5":re = "jkl";break;
            case "6":re = "mno";break;
            case "7":re = "pqrs";break;
            case "8":re = "tuv";break;
            case "9":re = "wxyz";break;
            default:break;
        }
        return re;
    }
}
```