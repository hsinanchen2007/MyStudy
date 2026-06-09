**思路：**
```
   考虑到这个单词规律是OneToOne模式，实现的方式是再用hashMap保存key,values值。
   1.key是不可重复的，所以可以保证key是唯一的。
   2.values是可重复的，如何实现唯一？实现values唯一的方式是遍历values即可，用
   一个布尔值判断，遍历后如果布尔值为false，表示是唯一的且可插入map。true表示
   OneToOne规律被打破，当前的字符在map集合中已经被另一个字符映射了。
```java []
        Map<String, String> map = new HashMap<String, String>();
        String[] s = str.split(" ");
        char[] chars = pattern.toCharArray();

        if (chars.length != s.length) return false;
        for (int i = 0; i < s.length; i++) {
            String aChar = chars[i] + "";
            String s1 = s[i];
            String s2 = map.get(aChar);
            if (s2 == null) {
                boolean isexit = false;
                Collection<String> values = map.values();
                for (String ss : values
                ) {
                    if (ss.equals(s1)) {
                        isexit = true;
                        break;
                    }
                }
                if (!isexit) {
                    map.put(aChar, s1);
                } else {
                    return false;
                }
            } else {
                if (!s2.equals(s1)) return false;
            }
        }
        return true;
```

![微信截图_20190722161651.png](https://pic.leetcode-cn.com/f9651061f181821028625d4ff971a7d58acc178279cf9f1e1d21818278e2ff05-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20190722161651.png)

**反思：** 时间复杂度O（n）,空间复杂度O(n^2). 空间上可以进行优化。
可以把每次存入都获取一次values，意味需要有多少个字符就需要重新获取多少次空间，
可以事先用一个set集合保存values的值，就不需要每次取出来了，借用一下QQ怪的代码，
```
public boolean wordPattern(String pattern, String str) {
        char[] chars = pattern.toCharArray();
        String[] s = str.split(" ");
        if(chars.length != s.length) {
            return false;
        }
        //存储pattern->str对应键值对
        HashMap<Character, String> map = new HashMap<>();
        //存储str不重复的value
        Set<String> set = new HashSet<>();
        for (int i = 0; i < chars.length; i++) {
            String s1 = map.get(chars[i]);
            if(s1==null){
                if(!set.contains(s[i])){
                    set.add(s[i]);
                    map.put(chars[i],s[i]);
                }else{
                    return false;
                }
            }else{
                //如果遇到不相等的值
                if(!s1.equals(s[i])){
                    return false;
                }
            }
        }
        return true;
    }

作者：qqguai
链接：https://leetcode-cn.com/problems/two-sum/solution/yong-yi-ge-hashmaphe-setjie-jue-by-qqguai/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```
以及运行的结果
![sss.png](https://pic.leetcode-cn.com/87e7e04f5b029848ab2247a57737334c0104cb80853c17a137c2d36ab19235bc-sss.png)

明显发现空间利用率小了一半。




