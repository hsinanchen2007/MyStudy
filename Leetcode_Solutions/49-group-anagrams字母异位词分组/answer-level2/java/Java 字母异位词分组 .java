### 解题思路
下面两个方法大同小异。
1.首先明确什么是"字母异位词","字母异位词"指字母相同，但排列不同的字符串。
假设字符串s = "abc", s的字母异位词是"abc" "acb" "bac" "bca" "cab" "cba" ;
n个字母组成的字符串有n!符合条件的字母异位词。
2.其次思考给定两个字符串如何判断他们是否为字母异位词呢？ 
我们将字符串按照字母序排列，如果相等即为字母异位词。
如"acb" "cba" 按照字母序排序以后均为"abc" 。
也就是说***字母异位词具有统一的形式***
3.保存结果：开一个HashMap，key存放每个排序后的字符串（统一形式），List存放key对应形式下的List。

### 代码

```java
class Solution {
    List<List<String>> ans = new ArrayList<>() ;
    HashMap<String,List<String>> map = new HashMap<>() ;
    public List<List<String>> groupAnagrams(String[] strs) {
        if(strs == null || strs.length == 0) return ans ;
        for(String s:strs){
            String temp = getString(s) ;
            if(!map.containsKey(temp)){
                map.put(temp,new ArrayList<>()) ;
            }
            map.get(temp).add(s) ;
        }
        for(Map.Entry<String,List<String>> entry:map.entrySet()){
            ans.add(entry.getValue()) ;
        }
        return ans ;
    }
    public String getString(String s){
        char[] ss = s.toCharArray() ;
        Arrays.sort(ss) ;
        return String.valueOf(ss) ;
    }
}


// class Solution {
//     List<List<String>> ans = new ArrayList<>() ;
//     HashMap<String,Integer> map = new HashMap<>() ;
//     public List<List<String>> groupAnagrams(String[] strs) {
//         if(strs == null || strs.length == 0) return ans ;
//         int index = 0 ; 
//         for(String s:strs){
//             String temp = getString(s) ;
//             if(!map.containsKey(temp)){
//                 map.put(temp,index) ;
//                 index++ ;
//                 ans.add(new ArrayList<>()) ;
//             }
//             ans.get(map.get(temp)).add(s) ;
//         }
//         return ans ;
//     }
//     public String getString(String s){ // 返回字符串s中所有字母排序以后组成的字符串  "bca" ---> "abc"
//         char[] ss = s.toCharArray() ;
//         Arrays.sort(ss) ;
//         return String.valueOf(ss) ;
//     }
// }



```