### 解题思路
![捕获9.PNG](https://pic.leetcode-cn.com/aa66a22cb9a7aacc9c398b37b2b7e4e080e73489269e644954ccb09390c3c13d-%E6%8D%95%E8%8E%B79.PNG)
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isValid(String s1,String s2){
        if(s1.length()!=s2.length()){
            return false;
        }
        int[] arr1=new int[26];
        int[] arr2=new int[26];
        for(int i=0;i<s1.length();i++){
            arr1[s1.charAt(i)-'a']++;
        }
        for(int j=0;j<s2.length();j++){
            arr2[s2.charAt(j)-'a']++;
        }
        for(int i=0;i<arr1.length;i++){
            if(arr1[i]!=arr2[i]){
                return false;
            }
        }
        return true;
    }
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> res=new ArrayList<>();
        if(strs==null||strs.length==0){
            return res;
        }
        int len=strs.length;
        boolean[] flag=new boolean[len];
        
        for(int i=0;i<len;i++){
            List<String> tmp=new ArrayList<>();
            if(flag[i])
                continue;
            tmp.add(strs[i]);
            flag[i]=true;
            for(int j=i+1;j<len;j++){
                if(isValid(strs[i],strs[j])&&!flag[j]){
                    tmp.add(strs[j]);
                    flag[j]=true;
                }
            }
            res.add(tmp);
        }
        return res;
    }
}





























```