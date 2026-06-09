### 解题思路
刚学字符串转char数组，就试一下，从haystack的第一个开始遍历和needle比较，遍历次数为两者长度之差+1，for体系里再进行循环比较


### 代码

```java
class Solution {
    public int strStr(String haystack, String needle) {
        char[] hay=haystack.toCharArray();
        char[] need=needle.toCharArray();
        if(need.length==0){
            return 0;
        }
        if(need.length>hay.length) {
        	return -1;
        }
        int j=0;
        for(int i=0;i<hay.length-need.length+1;i++){
            int k=i;
            while(hay[k]==need[j]){
                if(j==need.length-1) return i;
                k++;
                j++;
            }
            j=0;
        }
        return -1;
    }
}
```