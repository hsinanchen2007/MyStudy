### 解题思路
此处撰写解题思路
别怕，这个题目限定了word集合里面的长度，都是一致的，那么就可以按照这个长度去一个坐标一个坐标的遍历S字符串
字符串每次从i index出发，每次递增一，且每次检索从index出发的word长度字符子串，并拿去进行比较，用hashmap的containsKey方法
如果匹配，那么就从temp_map (每个index都进行一个hash初始化，在检索匹配之后用来比较sourcemap，从而得出是不是真的匹配上了，)里面hash获取其对应的值，并+1，这里可以直接跟source_map里面的对应value进行比较，如果此处就超过了source——Map,就完全可以跳过该index，直接进行下一个index的匹配。
### 代码

```java
class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> res=new ArrayList<Integer>();
        //source_map initial
        HashMap<String, Integer> source_map=new HashMap<String, Integer>();

        if(words.length==0)
            return res;
        //set the source_map
        for(int i=0;i<words.length;i++)
        {
            int value=source_map.getOrDefault(words[i],0);
            source_map.put(words[i],value+1);
        }
/       //get the word len
        int word_len=words[0].length();
        //get the words' size
        int nums=words.length;
        for(int i=0;i<s.length()-word_len*nums+1;i++)
        {
            // initial temp_map each time
            HashMap<String, Integer> temp_map=new HashMap<String, Integer>();
            int count=0;
            //match the nums times.
            while(count<nums)
            {
                String sub_word=s.substring(i+count*word_len,i+(count+1)*word_len);
                if(source_map.containsKey(sub_word))
                {
                    int temp=temp_map.getOrDefault(sub_word,0);
                    //if bigger than sourcemap. just break!!!
                    if((temp+1)>source_map.getOrDefault(sub_word,0))
                        break;
                    temp_map.put(sub_word,temp+1);
                }
                else
                {
                    //can not find the key in sourcemap. just break!!
                    break;
                }


                //accumulate the match words in temp_map
                count++;
            }
            // if the source map equals the temp map, we record the index:i
            if(count==nums)
                res.add(i);
        }
        return res;
    }
}
```