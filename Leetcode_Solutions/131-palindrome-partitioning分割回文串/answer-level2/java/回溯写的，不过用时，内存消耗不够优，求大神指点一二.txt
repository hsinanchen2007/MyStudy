### 解题思路
回溯 求指点，比如回溯和复制对象的地方，能不能有更巧妙的做法

### 代码

```java
class Solution {
    List ress = new ArrayList<List<String>>();
    public List<List<String>> partition(String s) {
        if (s.length() == 0)
            return ress;
        Combination(s, 0, new ArrayList<>());
        return ress;
    }
    private void Combination(String s, int index, List<String> res) {
        if (index == s.length()) {
            // 复制对象
            ArrayList<String> nres = new ArrayList<>();
            for (String re : res)
                nres.add(re);
            ress.add(nres);
            System.out.println("last" + ":" + res);
            return;
        }
        
        for (int i = index + 1; i <= s.length(); i++) {
            String str = s.substring(index, i);
            if (isPalindrome(str)) {
                res.add(str);
                System.out.println(i + ":" + res);
                Combination(s, i, res);
                //回溯
                res.remove(res.size() - 1);
            }
        }
    }

    private boolean isPalindrome(String str) {
        for (int i = 0, j = str.length() - 1; i < j; i++, j--)
            if (str.charAt(i) != str.charAt(j))
                return false;
        return true;
    }
}
```