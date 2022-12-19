![QQ图片20191130232359.png](https://pic.leetcode-cn.com/51b0dba83bcf4f98942e78fb246376cca8a270a9b88be30b212788f9f8334cba-QQ%E5%9B%BE%E7%89%8720191130232359.png)



```
class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        //相邻两个单词进行比较
     for(int i=0; i<words.length-1; i++) {
            String wordFirst = words[i];
            String wordSecond = words[i+1];

            //后一个单词是以前一个单词开头
            if(wordSecond.startsWith(wordFirst)) {
                continue;
            }

            //前一个单词是以后一个单词开头
            if(wordFirst.startsWith(wordSecond)) {
                return false;
            }

            //查找两个单词间第一个不同的字母
            int index = 0;
            while(wordFirst.charAt(index) == wordSecond.charAt(index)) {
                index++;
            }

            //在字母表中查询两个字母的索引,并比较大小
            if(order.indexOf(wordFirst.substring(index, index+1)) < order.indexOf(wordSecond.substring(index, index+1))) {
                continue;
            } else {
                return false;
            }
        }

        return true;   
    }
}
```

仅供参考.  
==================欢迎指教^-^================