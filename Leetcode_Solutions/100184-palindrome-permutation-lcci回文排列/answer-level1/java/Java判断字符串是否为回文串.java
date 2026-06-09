### 解题思路
明白回文串的特点:
    a.字符串长度为1也是回文串 
    b.回文串只有一个字符个数为奇数，其余字符个数为偶数，若出现2个或2个以上字符个数为奇数的字符，则表示非回文串
 

### 代码

```java
class Solution {
    public boolean canPermutePalindrome(String s) {
          if(s.length()==1){
            return true;
        }

        char [] temp = s.toCharArray();
        Map<Character,Integer> map = new HashMap<>();
            int value = 0;
    //统计字符串中每个字符出现的次数
        for (int i=0;i<temp.length;i++){
           if(map.containsKey(temp[i])){
               map.put(temp[i],map.get(temp[i])+1);
           }else{
               map.put(temp[i],1);
           }
        }
    //统计有几个字符个数是奇数个，超过一个就是非回文串
        int count = 0;
        for (Character key: map.keySet()) {
            int val =map.get(key);
            if(val%2 !=0){
                count++;
                continue;
            }

        }

        if(count>1){
            return false;
        }

        return true;
    }
}
```