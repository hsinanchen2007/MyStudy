![image.png](https://pic.leetcode-cn.com/79cd0fa6f1af762a7cbaed643425e713f8a2b5d5bb2ba7245da127954719260a-image.png)

代码如下
```
      public boolean CheckPermutation(String s1, String s2) {
        if (s1==null && s2 == null){
            return true;
        }
        if (s1 == null || s2 == null){
            return false;
        }
        if (s1.length() != s2.length()){
            return false;
        }
        List<Character> characters1 = new ArrayList<>();
        for (char c : s1.toCharArray()){
            characters1.add(c);
        }
        for (char c : s2.toCharArray()){
            try {
                characters1.remove(Character.valueOf(c));
            }catch (Exception e){
                return false;
            }
        }
        if (!characters1.isEmpty()){
            return false;
        }
        return true;
    }
```
