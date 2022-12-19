### 解题思路
本题的难点是如何解决多个单词串联组合的问题，主要思路是先利用words数组构成哈希表，再将字符串s按照单词长度一次次取出子串temp，然后一个个取出temp中的单词与哈希表中进行比对，如果不存在该单词则进行下一个子串temp的获取；若存在该单词且出现的value大于0则将该value减1，若存在该单词但是value为0说明截取的temp子串中某一个单词多了，故进行下一个子串temp的获取。
1、根据入参单词数组构建一个单词->出现次数的哈希表map1
2、利用滑动窗口，每次向后滑动一个字符
3、哈希表深拷贝为map
4、判断子串是否由words构成

### 代码

```java
class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> list = new ArrayList<>();
        if(s == null || s.length() <= 0 || words.length == 0) return list;
        //窗口大小
        int len = words[0].length()*words.length;
        //单词长度
        int wordlen = words[0].length();
        //哈希表：key为单词，value为单词在字符串数组中出现的次数
        Map<String,Integer> map1 = new HashMap<>();
        for(int i=0;i<words.length;i++){
            if(map1.containsKey(words[i])) map1.put(words[i],map1.get(words[i])+1);
            else map1.put(words[i],1);
        }
        //窗口的左右两点
        int L = 0;
        int R = L+len;    
        while(R<=s.length()){
            //该标记记录是否需要break进行下一次循环
            int flag = 0;
            //按窗口大小从字符串中一次次取出子串
            String temp = s.substring(L,R);
            //哈希表的深拷贝，因为每次判断子串都需要用到
            Map<String,Integer> map = new HashMap<>();
            map.putAll(map1);
            //判断子串temp是否由words组成，读到一个单词，哈希表中value就减1，若为0或者不存在该单词则break进行下一个子串temp的获取
            for(int i=0;i<temp.length();i+=wordlen){
                String sub = temp.substring(i,i+wordlen);
                if(map.containsKey(sub)){
                    if(map.get(sub)==0){
                        flag = 1;
                        break;
                    };
                    if(map.get(sub)>0) map.put(sub,map.get(sub)-1);
                }
                else{
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                list.add(L);
                L++;
                R++;
            }
            if(flag == 1){
                L++;
                R++;
            }
        }
        return list;
    }
}
```