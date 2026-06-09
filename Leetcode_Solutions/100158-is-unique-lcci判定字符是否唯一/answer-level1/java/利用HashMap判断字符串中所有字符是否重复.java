### 解题思路
此处撰写解题思路
* 将字符串转化为字符数组
* 设置一个Map<Character,Integer> 数组，key为字符，Integer为出现次数
* 遍历字符数组
* 如果出现字符不等于1，则停止遍历，返回false
* 如果遍历结束且没有返回false则返回truetrue


### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        char[] array=astr.toCharArray();
        Map<Character,Integer> map=new HashMap<>();
        for(char c:array){
            map.put(c,map.getOrDefault(c,0)+1);
            if(map.get(c)!=1)
                return false;
        }
        return true;
    }
}
```