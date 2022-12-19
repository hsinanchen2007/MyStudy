### 解题思路
1、判断字符串是否为空，或者长度为0；
2、从最后一个字符开始向前遍历，标记最后一个单词的开始位置；如果不存在，则遍历结束后 return 0；
3、如果存在最后一个单词，向前查找过程中，长度++；
4、判断终止条件：到第一个字符为止，或者遇到下一个空格' '，跳出循环。

效果：执行用时 :0 ms, 在所有 java 提交中击败了100.00%的用户
内存消耗 :35.9 MB, 在所有 java 提交中击败了74.00%的用户

### 代码

```java
class Solution {
    public int lengthOfLastWord(String s) {
        if(s==null || s.length()==0){
            return 0;
        }
        int i = s.length()-1;
        int start = -1;
        int rl = 0;
        while(i>=0){
            if(start<0 && (s.charAt(i)!= ' ')){
                start=0;
                rl++;
            }else if(start==0 && s.charAt(i)!= ' '){
                rl++;
            }else if(start==0 && s.charAt(i)== ' '){
                break;
            }
            i--;
        }
        return rl;
    }
}
```