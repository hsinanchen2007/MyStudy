### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        ArrayList<Character> list=new ArrayList<>();
        int count=0;
        for(int i=0;i<astr.length();i++){
            count+=astr.charAt(i);
            if(!list.contains(astr.charAt(i)))
            list.add(astr.charAt(i));
        }
        for(int i=0;i<list.size();i++)
        count-=list.get(i);
        return count==0;
    }
}
```