### 解题思路
1、求出每个字符串的hashCode
    注意这里的hashCode不能是数字，因为有可能存在重复后的数字相同。
    这里应该用String,将原字符串的每一位char排序后重新组合在一起

2、再根据hashCode进行分组

### 代码

```java
class Solution {

   private String getHashCode(String str){
       int length = str.length();
       char[] hashCodeArray = new char[length];
        int j = 0;
        for(int i=0;i<length;i++){
            hashCodeArray[j++]=(char)str.charAt(i);
        }
        Arrays.sort(hashCodeArray);
        String hashCodeStr = String.valueOf(hashCodeArray);

        return hashCodeStr;
    }

    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String,List<String>> hashMap = new HashMap<>();
        for(String item:strs){
            String hashCode = getHashCode(item);
            List<String> list = hashMap.getOrDefault(hashCode,new ArrayList<String>());
            list.add(item);
            hashMap.put(hashCode,list);
        }
        List<List<String>> result = new ArrayList<>();
        for(List<String> list:hashMap.values()){
            result.add(list);
        }
        return result;
    }
}
```