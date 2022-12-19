### 解题思路
后续 把 kmp，sunday， bm 等算法学下再写

### 代码

```java
class Solution {
    public int strStr(String haystack, String needle) {
        return myIndexOf(haystack, needle);
        
    }

    public int myIndexOf(String source, String target){
        int srcLen = source.length();
        int tarLen = target.length();
        if (tarLen == 0){
            return tarLen;
        }
        char first = target.charAt(0);
        int max = srcLen - tarLen;
        for (int i = 0; i <= max; i++){
            if(source.charAt(i) != first){
                while(++i <= max && source.charAt(i) != first);
            }
            if (i <= max){
                int j = i+1;
                int end = j + tarLen - 1;
                for(int k = 1; j < end && source.charAt(j) == target.charAt(k); j++, k++);
                if (j == end) return i;
            }


        }
        return -1;
    }
}
```