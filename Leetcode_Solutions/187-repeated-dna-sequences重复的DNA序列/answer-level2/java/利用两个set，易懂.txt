### 解题思路


### 代码

```java
class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        List<String> ans=new ArrayList<>();
        Set<String> set1=new HashSet<>();//存已经遍历过的字符串
        Set<String> set2=new HashSet<>();//存满足条件的字符串
        if(s.length()<10)
        return ans;
        for(int i=0;i<=s.length()-10;i++)
        {
            String temp=s.substring(i,i+10);//每次截取一个长度为0的子串
            if(set1.contains(temp))//利用set不重复的特性，可以直接加入
                set2.add(temp);
            set1.add(temp);
        }
        ans.addAll(set2);
        return ans;
    }
}
```