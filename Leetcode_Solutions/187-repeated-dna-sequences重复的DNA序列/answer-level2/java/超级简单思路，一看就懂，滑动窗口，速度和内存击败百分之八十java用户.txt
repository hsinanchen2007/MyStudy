  这个题一看是个字母单词，找子串重复很容易就想到滑动窗口，以十个字母为窗口滑动一轮，直接得出结果。
把得到的单词计入hashmap之后，得到的单词存入计数加一，得到计数等于1就加入list，否则不加入list直接去重完成。超级简单。说的不太明白直接上代码吧。
```
class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        List<String> res=new ArrayList<>();
        //s长度小于等于10当然不会有重复子串
        if(s.length()<=10)
            return res;
        //窗口大小
        int window=10;
        int start=0;
        //记录出现过的子串
        Map<String,Integer> sMap=new HashMap<>();
            //左为0，右为窗口大小，开始滑动每轮while循环lr自增1
            int l=0;
            int r=window;
            while(r<=s.length()){
                //获取当前子串
                String temp=s.substring(l,r);
                //如果已经记录存在，返回对应value值，否则返回1
                int count=sMap.getOrDefault(temp,0);
                //value值加1，存入map
                sMap.put(temp,count+1);
                //第一次重复出现的时候加入list，之后再出现此单词不用加入list了，等于去重
                if(count==1){
                    res.add(temp);
                }
                l++;
                r++;
            }
        return res;
    }
}
```
