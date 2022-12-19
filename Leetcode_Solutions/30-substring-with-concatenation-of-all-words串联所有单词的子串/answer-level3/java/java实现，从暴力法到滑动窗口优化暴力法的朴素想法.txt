这道题要把每个单词看成整体，每个不同的单词看作是不同的字符，单词串就看成是特殊的字符串。

注意：s中的单词未必是长度相等。words中可能存在相同的单词。

**思路一：暴力法** words中的单词长度都一样，大幅降低了这道题的难度，所以这个特点要充分利用。所以遍历s的每个子串，分别检查每个字串中是否符合要求。

用一个hashmap存储words中的每个单词及其在words中出现的次数；每遍历一个子串都要用一个hashmap存储被遍历子串中出现的words中存在的单词及其在子串中出现的次数。

重点是理解这个“要求”：1.words中的每个单词都**必须出现一次**。2.words中的每个单词**必须连续出现**。

反言之：检查每个子串的过程中，出现words中的不存在的单词则结束检查；出现与words中相等的单词，但是出现的次数超过其在words中出现的次数则结束检查。

```java
public List<Integer> findSubstring(String s, String[] words) {
    List<Integer> res=new ArrayList<>();
    if (words==null||words.length==0)return res;
    //单词个数、单词长度
    int wordNum = words.length,wordLen=words[0].length();
    //将words每个单词及其个数存入hashmap
    HashMap<String,Integer> allWords=new HashMap<>();
    for (String word : words) {
        Integer value = allWords.getOrDefault(word, 0);
        allWords.put(word,++value);
    }
    //遍历s每一个子串,剩余不足wordNum*wordLen个字符的子串不需要遍历
    for (int i = 0; i < s.length() - wordNum * wordLen + 1; i++) {
        //将子串中出现的和words中相等的单词及其出现次数存入hashmap
        HashMap<String,Integer> hasWords=new HashMap<>();
        //记录字串中和words中相等单词数量
        int count=0;
        //统计字串中连续和words中相等的单词
        while (count<wordNum){
            String word = s.substring(i + count * wordLen, i + (count + 1) * wordLen);
            //如果word匹配words中的单词，就统计其出现次数
            if (allWords.containsKey(word)){
                Integer value = hasWords.getOrDefault(word, 0);
                hasWords.put(word,++value);
                //如果word出现次数超过words中这个单词的总数量则结束统计
                if (hasWords.get(word)>allWords.get(word))break;
            }else {
                //如果字串中出现于words中所有单词都不匹配的word则结束统计
                break;
            }
            //增加成功与words中匹配的单词数量
            count++;
        }
        if (count==wordNum)res.add(i);
    }
    return res;
}
```

时间复杂度：O(n*m)	n是s长度，m是words中单词个数。

**思路二：滑动窗口优化暴力法** 用循环内的map(haswords)来保存窗口中匹配的单词，再用一个指针标记窗口当前的起始位置。

暴力方法中有几个需要优化的地方：

1. 匹配成功：

   
![question30 1.png](https://pic.leetcode-cn.com/47bcb1006bf542350a3943defb6a7f3aabf8de9921b67ec625b30020691c66de-question30%201.png)
   判断i=0这个子串符合要求，如果继续按照思路一的方法判断。当i=3的时候，依然一次校验每个单词，但是“foofoo”这两个单词已经在i=0子串的时候校验过了。所以暴力法中的hasword这个map并不需要每次都清空，只需要移除“bar“之后，从i=9的单词开始判断就好了。

2. 匹配失败，有不匹配的单词：

   ![3MyycD.png](https://pic.leetcode-cn.com/4b9119c4a23a99e049890a320e1b82b31eeca057d9151dcc6bb390fa01324313.png)

   判断i=0子串时出现了“the”这个不匹配的单词导致匹配失败。i=3、i=6这些子串都包含“the”这个单词，所以都不能匹配成功，所以窗口直接移动到i=9继续校验即可。

3. 匹配失败，单词匹配但是数量超出：

   ![3Mys1O.png](https://pic.leetcode-cn.com/938737e25d1224160e9a4d818aa6beaf1eb8877d612d1313202236b58783184a.png)

   i=0字串中“bar”出现两次，但是words中只有一个"bar"所以匹配失败。窗口移动到i=3,移除了“foo”但是“bar”依然多出一个，所以一定不匹配。窗口移动到i=6的时候移除了“bar”，就可以按照正常流程继续判断了。

不难发现，上述几种情况的描述时，不再是每次移动一个字符，而是每次移动单词长度。但是s中的单词不一定都是刚好符合wordLen，如何解决这种情况？

答：分成wordLen种情况，分别进行判断。分别从i=0开始每次移动一个单词长度、从i=1开始每次移动一个单词长度、从i=2开始每次移动一个单词长度、、、直至从i=wordLen-1开始每次移动一个单词长度。

```java
public List<Integer> findSubstring(String s, String[] words) {
    List<Integer> result=new ArrayList<>();
    if (s==null||words==null||words.length==0)return result;
    int wordsNum = words.length,wordLen=words[0].length();
    //将words中的单词及其数量存入hashmap
    HashMap<String,Integer> allWords=new HashMap<>();
    for (String word : words) {
        Integer value = allWords.getOrDefault(word, 0);
        allWords.put(word,value+1);
    }
    //分成wordLen中情况，分别从0开始每次移动一个单词长度~从wordLen-1开始每次移动一个单词长度
    for (int j=0;j<wordLen;j++){
        //haswords存放当前子串中匹配的单词及其个数，count当前子串匹配的单词数量
        HashMap<String,Integer> haswords=new HashMap<>();
        int count=0;
        //遍历从j开始的每个子串，每次动一个单词长度
        for (int i=j;i<s.length()-wordLen*wordsNum+1;i+=wordLen){
            //防止情况三出现之后，情况一继续移除
            boolean hasRemoved=false;
            while (count<wordsNum){
                String curWord = s.substring(i + count * wordLen, i + (count + 1) * wordLen);
                //当前单词匹配，加入haswords
                if (allWords.containsKey(curWord)) {
                    Integer value = haswords.getOrDefault(curWord, 0);
                    haswords.put(curWord,value+1);
                    count++;
                    //情况三，当前单词匹配，但是数量超了
                    if (haswords.get(curWord) > allWords.get(curWord)) {
                        hasRemoved=true;
                        //从i开始逐个单词，从haswords中移除，removeNum记录移除的单词个数
                        int removeNum=0;
                        while (haswords.get(curWord) > allWords.get(curWord)) {
                            String fristWord = s.substring(i + removeNum * wordLen, i + (removeNum + 1) * wordLen);
                            Integer v = haswords.get(fristWord);
                            haswords.put(fristWord,v-1);
                            removeNum++;
                        }
                        //移除完毕之后，更新count
                        count-=removeNum;
                        //移动i的位置(注意removeNum要-1，因为跳出当前循环之后，i还要+wordLen)
                        i+=(removeNum-1)*wordLen;
                        break;
                    }
                }else{//情况二，当前单词不匹配
                    //清空haswords
                    haswords.clear();
                    //i移动到当前单词位置(因为跳出当前循环之后，i还要+wordLen)
                    i+=count*wordLen;
                    count=0;
                    break;
                }
            }
            //情况一，匹配成功
            if (count==wordsNum)result.add(i);
            //如果情况三没有出现
            if (count>0&&!hasRemoved){
                //移除成功匹配子串的第一个元素
                String fristWord = s.substring(i, i + wordLen);
                Integer v = haswords.get(fristWord);
                haswords.put(fristWord,v-1);
                count--;
            }
        }
    }
    return result;
}
```

时间复杂度：O(n*wordLen)	这个时间复杂度不敢确定算的对。。。

---

思路二的代码，确实非常冗杂。接受批评o(╥﹏╥)o

本人菜鸟，有错误请告知，感激不尽！

更多题解和学习记录博客:[博客](https://blog.csdn.net/qq_42758551)**、**[github](https://jerrymouse1998.github.io/)