    执行用时 :1 ms, 在所有 Java 提交中击败了98.75%的用户
    内存消耗 :34.7 MB, 在所有 Java 提交中击败了100.00%的用户
    
    我写完代码后来看java其他解题思路，发现都会有用到StringBuffer的。
    
    奈何自己基础太渣，写的时候完全不记得，QAQ

    我的解题思路就是：两条线并行，第一条碰到".",第二条就自己加"[.]"，再更新第二条索引。

```
char[] ch = address.toCharArray();
        char[] ch1 = new char[address.length()+8];
        for (int i = 0,j=0; i < ch1.length && j<ch.length; i++,j++) {
            if (ch[j]!='.') ch1[i]=ch[j];
            else{
                ch1[i]='[';
                ch1[i+1]='.';
                ch1[i+2]=']';
                i = i+2;
            }
        }
        return String.valueOf(ch1).trim();
```