### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int calculateTime(String keyboard, String word) {
        //哈希表法:用Map映射键盘值
        Map<Character,Integer> map=new HashMap<>();
        for(int i=0;i<keyboard.length();i++)
        {
            char ch=keyboard.charAt(i);
            map.put(ch,i);
        }
        int ans=map.get(word.charAt(0));  //机械手臂从0号索引上方开始
        for(int i=1;i<word.length();i++)
            ans+=Math.abs(map.get(word.charAt(i))-map.get(word.charAt(i-1)));
        return ans;
    }
}
```