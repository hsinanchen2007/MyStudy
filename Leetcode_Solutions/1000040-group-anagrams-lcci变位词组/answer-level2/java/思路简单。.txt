
```java []
class Solution {
    //思路，使用单词进行字典排序，使用map的value，记录单词的位置。
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String,List<Integer>> map = new HashMap<>();
        for(int i = 0 ; i < strs.length ; i++){
            char[] c = strs[i].toCharArray();
            Arrays.sort(c);
            String str = new String(c);
            //如果已经存在，就把当前下标加入value的list中。
            if(map.containsKey(str)){
                List<Integer> list = map.get(str);
                list.add(i);
            }else{
                //若不存在，创建新的list，保存。
                List<Integer> list = new ArrayList<>();
                list.add(i);
                map.put(str,list);
            }
        }
        //组装返回数据。
        java.util.Collection<List<Integer>> c = map.values();
        List<List<String>> ret = new ArrayList<>();
        for(List<Integer> ls : c){
            List<String> ch = new ArrayList<>();
            for(Integer i : ls){
                ch.add(strs[i]);
            }
            ret.add(ch);
        }
        return  ret;
    }
}
```
![image.png](https://pic.leetcode-cn.com/132e3840261ddf83779434b282969ee1c44ffcaf0093c4b0536e567bb86b72a5-image.png)
