

![捕获.PNG](https://pic.leetcode-cn.com/7a05d6697a00d88b4ac9ad7760e44c4bc756dc6b7dcacc998bba2f958dccde79-%E6%8D%95%E8%8E%B7.PNG)




字典树的添加就不陈述了，前面左转208 [笑_笑]。


假设字符串为"apple"，逐个将字母丢进search进行判断，首先对下标为0的 a 通过其长度进行判断是否为单词的末尾（是否为单词末尾在addWord()中设置），是则直接返回true，匹配结束；否则false。
然后判断是否为'.'，如果为'.'则进行逐一判断，判断条件是不为空且节点中存在，图中的b和p都满足此条件，先会取b，但如果取b,但ab与apple的长度不符且b又不是单词末尾，所以会递归回到此层判断最终选择p；如果不为'.'则判断此字母范围是否在a-z之间及节点中是否存在此字母，false则直接返回，匹配结束，否则二次进入search进行判断下标为1的 p。
依据以上规则，多次判断会最终到达e。


![字典树前后缀匹配.png](https://pic.leetcode-cn.com/b7ae2d55d254016fff28e7de6421df3122b209e51db214a7548321ffe3d8fe0a-%E5%AD%97%E5%85%B8%E6%A0%91%E5%89%8D%E5%90%8E%E7%BC%80%E5%8C%B9%E9%85%8D.png)


有点粗糙，请见谅。。。



```java

public class WordDictionary {

    private boolean isEnd;
    private WordDictionary[] links = new WordDictionary[26];

    public WordDictionary(){
        this.isEnd = false;
    }

    // 添加单词
    public void addWord(String word){
        WordDictionary node = this;
        for (int i=0;i<word.length();i++){
            if (node.links[word.charAt(i)-'a'] == null){
                node.links[word.charAt(i)-'a'] = new WordDictionary();
            }
            node = node.links[word.charAt(i)-'a'];
        }
        node.isEnd = true;
    }

    public boolean search(String word){
        WordDictionary node = this;
        return search(node,word,0);
    }

    // 单词匹配 - 深度优先算法
    public boolean search(WordDictionary node,String word,int index){
        // 判断是否为单词末尾
        if (index == word.length()){
            return node.isEnd==true?true:false;
        }
        if (word.charAt(index) == '.') {
            for (WordDictionary each:node.links) {
                // 不能为空节点
                if (each!=null && search(each, word, index + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            // 不为空且字母属于a-z范围
            if (word.charAt(index) < 'a' || word.charAt(index) > 'z' || node.links[word.charAt(index) - 'a']==null) {
                return false;
            }
            return search(node.links[word.charAt(index) - 'a'], word, index + 1);
        }

    }

}

```
