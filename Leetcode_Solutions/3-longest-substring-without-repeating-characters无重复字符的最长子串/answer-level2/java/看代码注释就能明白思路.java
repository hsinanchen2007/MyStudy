### 解题思路
看注释应该就可以理解流程，简单理解就是在遍历过程中把上个无重复子串与下个无重复子串相冲突的部分扔掉，比如 “abcbde”,那么“abc”和“cbde”冲突的“ab”扔掉
### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        char[] strs = s.toCharArray();
        String str = "";    // 无重复子串(可能是未完成时)
        int maxLength = 0;  // 最长的无重复子串的长度
        int currentLength = 0; // 未完成时的无重复子串的长度
        for(int i = 0;i<strs.length;i++) {
            if(str.contains(strs[i]+"")){ //此时str为一个无重复子串
                if(currentLength > maxLength){ //判断这个无重复子串的是否是已知最长，是，覆盖
                    maxLength = currentLength;
                }
                int nextStart = str.lastIndexOf(""+strs[i])+1; //得到下个无重复子串的初始位置，相对于str
                str = (str+strs[i]).substring(nextStart); //将重复字符和其之前部分截取，加入此时遍历的字符，此时str为下个无重复子串（未完成时）
                currentLength = str.length(); //修改下个无重复子串的长度（未完成时）
            }else {
                str = str + strs[i]; //添加进无重复子串
                currentLength ++;    //长度加一
            }
        }
        //解决当最后一个子串不走if，无法判断这个无重复子串的是否是已知最长
        if(currentLength > maxLength){
            maxLength = currentLength;
        }
        return maxLength;
    }
}
```