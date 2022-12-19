### 解题思路
此题很简单分为下面几种情况：
1、字符完全相等，返回true；
2、26个字符绕回字符串"abcdefghijklmnopqrstuvwxyz","bcdefghijklmnopqrstuvwxyza"，最后转a的时候会触发头部转换。
3、其中有交替字符无法转换，如a->b a->c,返回false

### 代码

```java
class Solution {

    public boolean canConvert(String str1, String str2) {

        //第一种情况
        int len = str1.length();
        if (len <= 1 || str1.equals(str2)) {
            return true;
        }

        char[] str1chars = str1.toCharArray();
        char[] str2chars = str2.toCharArray();

        //第二种情况
        Arrays.sort(str1chars);
        Arrays.sort(str2chars);
        if (Arrays.equals(str1chars,str2chars)&&len==26) return false;
        return true;

        HashMap<Character, List<Character>> tmp = new HashMap();

        //第三种情况
        for (int i = 0; i < len; i++) {
            if (tmp.get(str1chars[i]) == null) {
                List<Character> val = new ArrayList<>();
                val.add(str2chars[i]);
                tmp.put(str1chars[i], val);
            } else {
                List<Character> tmpval = tmp.get(str1chars[i]);
                if (!tmpval.contains(str2chars[i])) {
                    return false;
                }
                tmpval.add(str1chars[i]);
            }
        }

    }
}
```