  题中的words里面，所有的单词长度都是相同的，所以我们可以通过以单词长度为窗口进行滑动，通过hashmap查看单词是否存在就能轻松解决这个问题。
里面的一些代码进行了一点小优化

```
class Solution {
    public static List<Integer> findSubstring(String s, String[] words) {
        List<Integer> res=new ArrayList<>();
        if(s.length()==0||words.length==0)
            return res;
        //获取一个单词长度
        String twords=words[0];
        //单词长度*单词数得到整个子串的长度，作为串s的窗口
        int window=twords.length()*words.length;
        int start=0;
        //窗口长度window
        int end=start+window;
        int wordLen=words[0].length();
        Map<String,Integer> wordsMap=new HashMap<>();
        //将子串单词存入hashmap，key为单词，相同单词用value值来统计
        for(int i=0;i<words.length;i++){
            int count=wordsMap.getOrDefault(words[i],0);
            wordsMap.put(words[i],count+1);
        }
        //统计有多少个不同的单词，用来比较
        int request=wordsMap.size();
        while(end<=s.length()){
            //使用copy进行hashmap的操作，当找到一个子串单词符合要求，将copy中对应value-1
            Map<String,Integer> copy=new HashMap<>(wordsMap);
            int now=0;
            int l=start;
            //一个单词长度
            int r=l+wordLen;
            while(true){
                String temp=s.substring(l,r);
                //这个单词在子串中存在就进行比较，否则这一轮窗口不符合要求直接break，到下一个窗口
                if(copy.containsKey(temp)){
                    int count=copy.get(temp);
                    //当count等于0时说明之前这个单词的出现个数已经符合要求了，直接break
                    if(count>0){
                        count=count-1;
                        //如果找到了相同数量的单词，统计加一.
                        if(count==0){
                            now++;
                        }
                        copy.put(temp,count);
                    }else{
                        break;
                     }
                }else{
                    break;
                }
                if(r==end){
                    break;
                }
                //以单词长度滑动
                l=l+wordLen;
                r=r+wordLen;
            }
            //如果对应单词数都符合要求，入list
            if(now==request)
                res.add(start);
            start++;
            end++;
        }
        return res;
    }
}
```


[@lexisen](/u/lexisen/)感谢指正

