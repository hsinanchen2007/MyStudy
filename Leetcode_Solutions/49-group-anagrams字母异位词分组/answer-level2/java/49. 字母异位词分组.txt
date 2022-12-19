/**
 * Project:
 * Author : zhaozhen
 * Email  :
 * Date   : 2019/11/13
 *
 * 解题思路: 使用一个hashmap <String,List> key:排序后的字符串标识 List:排序后的字符串与Key相同的字符串存储再当前List中,  After that,湖片区hashMap 的values组成一个List 进行输出
 *
 */
```
public List<List<String>> groupAnagrams(String[] strs) {
    HashMap<String ,List<String>> hashMap = new HashMap<>();

    for(int i = 0;i < strs.length;i++){
        char[] key = strs[i].toCharArray();
        Arrays.sort(key);
        String str_key = String.valueOf(key);
        if(hashMap.containsKey(str_key)){
            hashMap.get(str_key).add(strs[i]);
        }else{
            List list = new ArrayList();
            list.add(strs[i]);
            hashMap.put(str_key,list);
        }
    }
    List lists = new ArrayList();
    for (List list : hashMap.values()) {
        lists.add(list);
    }

    return lists;
}
```