### 解题思路
回文吗，分两种情况  一种字符串的长度为奇数，一种为偶数：
一 如果为奇数 那么只允许中间的字符出现的次数为奇数个，其余的字符出现的次数全部为偶数；
二 如果为偶数 那么所有的字符出现的次数为偶数个
奥利给

### 代码

```java
class Solution {
    public boolean canPermutePalindrome(String s) {
      HashMap<Character,Integer>map=new HashMap();
        boolean flag=false;
        for(int i=0;i<s.length();i++){
            map.put(s.charAt(i),map.getOrDefault(s.charAt(i),0)+1);
        }
        if(s.length()%2==0){
            flag=true;
        }
        for(char c:map.keySet()){
            if(map.get(c)%2==0){
                continue;
            }else if(map.get(c)%2==1&&flag){
                return false;
            }else if(map.get(c)%2==1&&!flag){
                flag=true;
            }
        }
        return true;
    }
}
```