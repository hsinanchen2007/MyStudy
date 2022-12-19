### 解题思路
利用数字遍历，中心扩展

### 代码

```java
class Solution {
    public static String longestPalindrome(String s) {
        if(null == s || s.length()<=1){
            return s;
        }
        StringBuffer  stringBuffer = new StringBuffer();
        for (int i = 0; i < s.length(); i++) {
            stringBuffer.append(".");
            stringBuffer.append(s.charAt(i));
        }
        stringBuffer.append(".");
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < stringBuffer.length(); i++) {
            list.add(1);
        };
        for (int i = 1; i < stringBuffer.length()-1; i++) {
            int count = 1;
            while (i-count>=0 && i+count<stringBuffer.length() && stringBuffer.charAt(i-count) == stringBuffer.charAt(i+count)){
                count++;
            }
            list.set(i,count-1);
        }

        Integer maxV = list.stream().max(((o1, o2) -> o1.compareTo(o2))).get();
        for (int i = 0; i < stringBuffer.length() ; i++) {
            if(list.get(i).equals(maxV)){

                try {
                    String s1 = stringBuffer.substring(i-maxV,i+maxV+1);
                    return  s1.replace(".","");
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
        return "";
    }
}
```