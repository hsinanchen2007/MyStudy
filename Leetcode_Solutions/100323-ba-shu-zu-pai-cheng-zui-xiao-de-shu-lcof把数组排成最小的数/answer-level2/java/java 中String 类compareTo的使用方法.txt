String中**compareTo的源码**：
```
     /* @param   anotherString   the <code>String</code> to be compared.
      * @return  the value <code>0</code> if the argument string is equal to
      *          this string; a value less than <code>0</code> if this string
      *          is lexicographically less than the string argument; and a
      *          value greater than <code>0</code> if this string is
      *          lexicographically greater than the string argument.
      */
     public int compareTo(String anotherString) {
         int len1 = value.length;
         int len2 = anotherString.value.length;
         int lim = Math.min(len1, len2);
         char v1[] = value;
         char v2[] = anotherString.value;
 
         int k = 0;
         while (k < lim) {
             char c1 = v1[k];
             char c2 = v2[k];
             if (c1 != c2) {
                 return c1 - c2;
             }
             k++;
         }
         return len1 - len2;
     }
```

此题本质上即为字符串比较大小的题，先转化为字符串数组，从大到小排序后连在一起即可
```
str.sort((s1,s2)->(s1+s2).compareTo(s2+s1));
```

