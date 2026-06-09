### 解题思路
暴力破解

1.首先将每个数字和对应的字符存到map中
2.排除只有一个数字的边界
3.定义返回列表为空时，将第一个数字对应的字符串拆成字符放入列表中
4.当定义的返回列表不为空时，将列表中的每个元素与正在遍历的字符连接，然后放入到列表中

可改进的地方：中间结果用的都是String，可改成StringBuilder

### 代码

```java
class Solution {
    public List<String> letterCombinations(String digits) {
        //定义返回列表
        List<String> res = new ArrayList<String>();
        //将每个数字和对应的字符存到map中
        HashMap<String, String> key = new HashMap<String, String>();
                               key.put("2", "abc");key.put("3", "def");
        key.put("4", "ghi");  key.put("5", "jkl");key.put("6", "mno");
        key.put("7", "pqrs"); key.put("8", "tuv");key.put("9", "wxyz");
        //排除传入仅一个数字时边界条件
        if (digits.length() == 1) {
            for (int i = 0; i <key.get(String.valueOf(digits.charAt(0))).length(); i++) {
                res.add(String.valueOf(key.get(String.valueOf(digits.charAt(0))).charAt(i)));
            }
            return res;
        }
        //遍历每个传入的数字
        for (int i = 0; i < digits.length(); i++) {
            String value = key.get(String.valueOf(digits.charAt(i)));//传入数字对应value
            int len = value.length();//传入数字对应value的长度
            if (res.size() == 0) {
                for (int j = 0; j < len; j++) {
                    res.add(String.valueOf(value.charAt(j)));//刚进入程序时，返回列表为空，将第一个数字对应的值存入
                }
            } else {
                int resLen = res.size();
                for (int j = 0; j < resLen; j++) {
                    String tempKey = res.get(0);
                    for (int k = 0; k < value.length(); k++) {
                        res.add(tempKey + String.valueOf(value.charAt(k)));//返回列表中的每个元素与正遍历的元素组合
                    }
                    res.remove(tempKey);//返回列表中再次组合后，组合前的元素删除
                }
            }
        }
        return res;
    }
}
```