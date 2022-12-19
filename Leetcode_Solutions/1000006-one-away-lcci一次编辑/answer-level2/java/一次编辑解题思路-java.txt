### 解题思路
此处撰写解题思路
### 根据示例可以看出规律：从不相等的地方断开，前面部分一定对等，后面部分一定对等。
### 特殊情况考虑：1.长度差值超出2个（直接干掉）；2.长度差值有且只有一个；3.没有长度差值。
### 代码

```java
class Solution {
    public boolean oneEditAway(String first, String second) {
        //先找出长的字符串，然后长的字符串放在max变量，短的放在second变量
        String max = "";
        max = first.length() >= second.length()? first:second;
        second = first.length() < second.length()? first:second;
        //长度相差2的，就不在做判断
        if (max.length() - second.length() > 1) return false;
        //循环遍历是否每一个位置的字符都相等
        for (int i = 0 ; i < second.length(); i++){
            //如果不相等，max字符串就比second字符串多往后一位截取，否则，两字符串就都往后一位截取
            if (max.charAt(i) > second.charAt(i)){
                if (max.length() != second.length()){
                    max = max.substring(i + 1);
                    second = second.substring(i);
                }else{
                    max = max.substring(i + 1);
                    second = second.substring(i + 1);
                }
                //然后比较两个字符串是否相等
                return max.equals(second);
            }
        }
        //如果没有出现不等的情况，即所有的字符都相同
        return true;
    }
}
```