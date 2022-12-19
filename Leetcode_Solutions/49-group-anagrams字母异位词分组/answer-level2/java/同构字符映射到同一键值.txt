### 解题思路
整理出所有字符串里面字母从小到大的排列顺序 并创建对应的哈希表

### 代码

```java
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
         List<List<String>> result=new ArrayList<>();
        HashMap<String,List<String>>hashMap=new HashMap<>();

        for(int i=0;i<strs.length;i++){
            String temp=sequenceWords(strs[i]);
            if(hashMap.containsKey(temp)){
                List<String>list1=hashMap.get(temp);
                list1.add(strs[i]);
                hashMap.put(temp,list1);

            }else{
                List<String>list=new ArrayList<>();
                list.add(strs[i]);
                hashMap.put(temp,list);
            }

        }
        for(String temp:hashMap.keySet()){
            List<String>finallist=hashMap.get(temp);
            result.add(finallist);
        }
        return result;
    }
    public static String sequenceWords(String word){
        StringBuilder temp=new StringBuilder();
        char[] singleword=word.toCharArray();
        Arrays.sort(singleword);
        for(int i=0;i<singleword.length;i++){
            temp.append(singleword[i]);
        }
        return temp.toString();
    }

}

```