### 解题思路
逐个检查给定的单词，构造可用作拼接索引字符串的单词列表。

1、由于索引字符串S中每个单词后有个#，所以如果我们得到了可用作拼接索引字符串的单词列表之后，所求长度就是单词总长度加上单词个数。
2、在检查的过程中对于类似time和me这种，其中一个单词以另一个单词结尾的，只保留较长的单词即可。
3、其他细节都写在注释中了。

### 代码

```java
class Solution {
    public int minimumLengthEncoding(String[] words) {
        //存储最终用来拼接索引字符串的单词列表
        List<String> ws=new ArrayList();
        //现将第一个单词加到列表中
        ws.add(words[0]);
        //ws的遍历索引 for循环内部的变量外提
        int j=0;
        //对于words的每个单词检查完ws列表后是否应该添加进ws for循环内部的变量外提
        boolean add=false;
        //初始化为第一个单词的长度
        int totalLen=words[0].length();
        //从第二个单词开始往后检查
        for(int i=1;i<words.length;i++){
            j=0;
            add=true;
            while(j<ws.size()){
                //如果检查的单词长度大于等于ws中某个单词的长度，并且以ws中的单词结尾
                if(words[i].length()>=ws.get(j).length()&&words[i].indexOf(ws.get(j))==words[i].length()-ws.get(j).length()){
                    //总长度增加的长度差
                    totalLen+=words[i].length()-ws.get(j).length();
                    //更新ws中检查的单词
                    ws.set(j,words[i]);
                    add=false;
                    break;
                }
                //如果检查的单词长度小于ws中某个单词的长度，并且以ws中的单词以检查的单词结尾
                if(words[i].length()<ws.get(j).length()&&ws.get(j).indexOf(words[i])==ws.get(j).length()-words[i].length()){
                    add=false;
                    break;
                }
                j++;
            }
            //不满足上面检查的两个条件，需要新增到ws中的单词
            if(add){
                ws.add(words[i]);
                totalLen+=words[i].length();
            }
        }
        //加上#的数量
        totalLen+=ws.size();
        return totalLen;
    }
}
```