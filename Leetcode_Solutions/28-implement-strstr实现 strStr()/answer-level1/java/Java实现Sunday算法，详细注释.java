该算法的思路相较于KMP十分容易理解:
1. 构建一张偏移表，该表主要记录了模式串中的每一个字符，以及每个字符在模式串中出现的最右位置到尾部的距离+1，未在模式串中出现的字符对应的偏移距离都是"模式串长度+1"。
2. 有了偏移表之后开始比较，用idx作为当前查询索引，每次截取目标字符串的[idx，idx+模式串长度]子串和模式串比较，如果相等则返回idx。
3. 如果不相等，查看子串在目标串中的后一个字符c是否存在于偏移表中，如果存在则idx=idx+偏移表[c]；如果不存在idx=idx+模式串长度。循环直至idx+模式串长度>目标字符串长度。

```java
public int strStr(String haystack,String needle){
        if (needle.equals(""))return 0;
        int hLen=haystack.length(),nLen=needle.length();
        if (hLen<nLen)return -1;
//        创建偏移表
        Map<Character,Integer> offsetMap=new HashMap<>();
        for (int i=0;i<nLen;i++){
            offsetMap.put(needle.charAt(i),nLen-i);
        }
//        开始查找模式串
        int idx=0;
//        循环直至idx+模式串长度>目标字符串长度
        while (idx+nLen<=hLen){
//            截取目标字符串
            String cutHay = haystack.substring(idx, idx + nLen);
//            如果子串和模式串相等，则返回idx
            if (cutHay.equals(needle)){
                return idx;
            }else {
//                边界处理
                if(idx+nLen>=hLen)return -1;
//                如果子串在目标串中的后一个字符c是否存在于偏移表中
                if (offsetMap.containsKey(haystack.charAt(idx+nLen))){
                    idx+=offsetMap.get(haystack.charAt(idx+nLen));
                }else {
                    idx+=nLen;
                }
            }
        }
        return -1;
    }
```

时间复杂度：O(nm)， 但是该算法的平均情况可以达到O(n)。