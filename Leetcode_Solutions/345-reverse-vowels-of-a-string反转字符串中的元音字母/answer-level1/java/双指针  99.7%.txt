![image.png](https://pic.leetcode-cn.com/55e8423324bb9cf8879182b3721bcd1af3ace4aa1fe721e79d59d4927e5f6fe6-image.png)
每次判断遍历到的字母是不是元音字母。为了简洁，还可以将元音字母放入hashmap中，不过会占用一定内存。
```
public  String reverseVowels(String s) {
            if (s==null || s.length()<2)
                return s;
            //如果采用stringbuilder，不太好用双指针
            //采用将字符串转为字符数组来做
            char[] chars = s.toCharArray();
            int i=0,j=chars.length-1;
            while (i<j){
                while (i<j && (chars[i]!='a' && chars[i]!='e' && chars[i]!='i' && chars[i]!='o'&& chars[i]!='u'&& chars[i]!='A' && chars[i]!='E' && chars[i]!='I' && chars[i]!='O'&& chars[i]!='U'))
                    i++;
                while (j>i && (chars[j]!='a' && chars[j]!='e' && chars[j]!='i' && chars[j]!='o'&& chars[j]!='u'&& chars[j]!='A' && chars[j]!='E' && chars[j]!='I' && chars[j]!='O'&& chars[j]!='U'))
                    j--;
                if (i<j){
                    char temp = chars[i];
                    chars[i] = chars[j];
                    chars[j] = temp;
                }
                i++;j--;
            }
            return new String(chars);
        }
```
