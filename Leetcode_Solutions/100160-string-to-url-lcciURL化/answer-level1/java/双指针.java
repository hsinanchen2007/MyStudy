这道题个人感觉是想考数组的。不多说直接上步骤：
    1. 将字符串转成字符数组，转换后的数组长度肯定够用，因为题目已经说了。
    2. 从0到length遍历一遍数组，找到在这之间有几个空格，目的就是为了能确定最后的字符串长度。
    3. 剩下的就是如何将空格转成%20,两种方法：  
        1. 从前向后遍历，遇到空格就转换，但是这个方法有一个不好的地方就是涉及到了要将空格后的字符串整体后移的情况，太慢
        2. 从后往前遍历，因为你知道了一共需要改变几个空格，以及变换之后的字符串长度，所以可以从后往前遍历


```
 public String replaceSpaces(String S, int length) {
        char[] ch = S.toCharArray();
        int count = 0;
        for( int i = 0; i < length; i++ ) {
            if (ch[i] == ' ') count++;
        }
        int i = length + count*2 - 1;
        int j = length - 1;
        while( i != j ){
            if( ch[j] == ' ' ){
                ch[i] = '0';
                ch[i-1] = '2';
                ch[i-2] = '%';
                i = i - 3;
            }else {
                ch[i] = ch[j];
                i--;
            }
            j--;
        }
        return String.valueOf(ch).trim();
    }
```
