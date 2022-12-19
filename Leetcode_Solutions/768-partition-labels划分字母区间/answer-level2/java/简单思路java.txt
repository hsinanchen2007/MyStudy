### 解题思路
此处撰写解题思路
开一个数组lastIndexs保存在字符串S中字符最后出现的位置；
然后定义两个变量endIndex,startIndex分别用来保存子串的起始位置与结束位置；
一开始初始化endIndex=0;startIndex=endIndex;
外层一个while循环,内层一个for循环用来寻找子串；
for循环代码为关键；
for循环的条件有一条控制语句就是i=startIndex<=endIndex,这是肯定的；
循环语句内部从startIndex到lastIndex开始依次寻找字符出现的最后的位置，若这个位置的下标大于endIndex,则将其赋值给endIndex,否则,i后移查找，直至i>endIndex,这时跳出for循环，找出一个子串，add到list中。然后endIndex++,startIndex=endInedx,进行下一轮循环。
其实代码看上去有些复杂，还是挺容易理解的。
只要搞懂为什么要将endIndex置为startIndex到endIndex中出现的字符最后出现的位置即可。因为如果不把他设置为某个字符最后出现的位置，他可能会在之后的字符串中出现和前一个字符串中相同的字符，不符合题意，而且endIndex还要等于lastIndex[i]中最大的，只有选最大的，才能保证每一个在当前字符串中出现的字符不会再之后的字符串中出现；

### 代码

```java
class Solution {
    public List<Integer> partitionLabels(String S) {
        List<Integer> list=new ArrayList<>();
        int[] lastIndexs=new int[26];
        for(int i=0;i<S.length();i++) lastIndexs[S.charAt(i)-'a']=i;
        int endIndex=0;
        while(endIndex<S.length()){
            int startIndex=endIndex;
            for(int i=startIndex;i<S.length()&&i<=endIndex;i++){
                int lastIndex=lastIndexs[S.charAt(i)-'a'];
    
                if(lastIndex>endIndex) endIndex=lastIndex;
            }
            list.add(endIndex-startIndex+1);
            endIndex++;
        } 
        return list;    
    }
} 
```