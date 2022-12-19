# 49字母异位词分组
**最初的方法，比较粗糙**
```
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String,List<String>> map = new HashMap<>();
        for(String str:strs){
            List<String>templist=new ArrayList<>();
            String str1=str;
            char[] str2=str1.toCharArray();//String转换为字符数组
            Arrays.sort(str2);//将字符数组排序
            String list=new String(str2);//将字符数组排序，再转换为String类型
            if(map.containsKey(list)){//判断是否存档
                templist=map.get(list);//获取值
                templist.add(str);//将异位词加入
            }else{
                templist.add(str);
            }
            map.put(list,templist);//更新存档
        }
        List<List<String>> res= new ArrayList<List<String>>();
        for(Map.Entry<String,List<String>>entry:map.entrySet()){//遍历每一个Key的value，存入结果变量中。
            res.add(entry.getValue());
        }
        return res;
    }
}
```

可以简化
```
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String,ArrayList<String>> map=new HashMap<>();
        for(String str:strs){
            char[] ch=str.toCharArray();
            Arrays.sort(ch);
            String key=String.valueOf(ch);
            if(!map.containsKey(key))    map.put(key,new ArrayList<>());
            map.get(key).add(str);
        }
        return new ArrayList(map.values());
    }
}
```