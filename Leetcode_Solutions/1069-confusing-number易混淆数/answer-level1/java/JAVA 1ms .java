思路：
1.输入转字符数组，方便反转判断
2.遍历数组，同时生成翻转字符串，判断是否0,1,6,8,9. 否直接返回false
3. 判断是否与翻转后的字符串一致
代码如下：
 ```
class Solution {
    public boolean confusingNumber(int N) {
        Map<String, String> a = new HashMap(5);
        a.put("0", "0");
        a.put("1", "1");
        a.put("6", "9");
        a.put("8", "8");
        a.put("9", "6");
        String str = String.valueOf(N);
        String RN = "";
        for (char c:str.toCharArray()) {
            if (!a.containsKey(String.valueOf(c))) {
                return false;
            }
            RN = RN + a.get(String.valueOf(c)) ;
        }
        return !new StringBuffer(str).reverse().toString().equalsIgnoreCase(RN);
    }
}
```
