### 解题思路
赎金信问题，简单来说就是有两个字符串ransomNote和magazine,判断magazine是否含有ransomNate中每一个字符。
理解题意有两个要求需要注意：
  1.两个字符串中只含有小写字母
  2.找到符合要求的字母，只需要组成待组成字符串即可，因此不需要考虑顺序
有以下两种方法解决此问题
### 代码1

```java
class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
            //思路：记录每一个元素的个数，再比较查找是否有足够的个数
            int[] count=new int[26];
            for(char c:magazine.toCharArray()){
                count[c-'a']++;
            }
            for(char p:ransomNote.toCharArray()){
                count[p-'a']--;
                if(count[p-'a']<0){
                    return false;
                }
            }
            return true;
    }
}
```
###代码2：
```java
class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        //存放待查找字符在待查找字符串查找的起始位置
        int[] count=new int[26];
        for(char c:ransomNote.toCharArray()){
            int index=magazine.indexOf(c,count[c-'a']);
            //没有查找到此字符
            if(index==-1){
                return false;
            }
            //从此处查找的下一个位置开始查找下一次相同的字符串
            count[c-'a']=index+1;
            }
            return true;
    }
}

```
如有不足，请各位大佬多多指出。