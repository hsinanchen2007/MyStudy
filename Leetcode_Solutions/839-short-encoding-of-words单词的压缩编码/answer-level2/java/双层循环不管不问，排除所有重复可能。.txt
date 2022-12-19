### 解题思路
1. 去除重复字符串
2. 拼接成一个字符串
例如 一个单词
     [happy,ha,ppy,py,appy] 这些单词 只需要保存  ha#happy# 即可
因此 做两层循环，把所有可能的结尾包含全部去除！
把数组 变成[happy ,ha , , , ]
### 代码

```java
class Solution {
       public int minimumLengthEncoding(String[] words) {
        List<String> list = new ArrayList<String>();
        String result = "";
        if (words == null) {
            return 0;
        }
//一个单词的情况
        if (words.length < 2) {
            return words[0].length() + 1;
        }
        String[] arrays = words;
        for (int i = 0; i < arrays.length; i++) {
            for(int j=0;j<arrays.length;j++){
                if(i==j){
                    continue;//排除自身
                }else{
               // 如果 time me  atime  三个单词， 只保留atime     time和me置空
                    if(arrays[i].endsWith(arrays[j])){
                       arrays[j]="";
                    }
                }

            }
         
        }
        for(int k=0;k<arrays.length;k++){
            if(!"".equals(arrays[k])){
                result=result+arrays[k]+"#";
            }
        }
        return result.length();
    }

    }

```