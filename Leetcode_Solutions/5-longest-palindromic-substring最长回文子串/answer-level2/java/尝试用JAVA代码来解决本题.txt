### 解题思路
此处撰写解题思路
1.要返回回文字符串的话，必定要遍历该字符数组
2.要符合回文字符串的要求，那么从本次遍历的字符往后数，必定会存在一样的字符，否则不符合要求
3.假定本次遍历到的字符为f，调用getLastCharIndex方法，从后往前数，获取到多个f字符所在的下标
4.根据本次遍历到的字符f所在的下标：i，和获取到的f字符的下标targetIndex,调用checkStringIsPalindrome方法，从两端往中间一个一个字符进行对比，对于任意的n>0且n<(targetIndex-n)/2都有符合cs[i+n]==cs[targerIndex-n]这个条件，那么该字符串是回文字符串
5.如果调用了checkStringIsPalindrome方法并且返回为true，说明是回文字符串，并且该字符串比之前遍历到的要更长，就保存起来，进行下次遍历

### 代码

```java
class Solution {
    public String longestPalindrome(String s) {
        if ("".equals(s)){
            return "";
        }
        if (s.length() == 1){
            return s;
        }
        String result = null;
        int maxLength = 0;
        char[] cs = s.toCharArray();
        for (int i = 0;i<cs.length;i++){
            //从最左边每个字符开始数,获取最后一个相同字符所在的位置，如果获取不到，说明该字符唯一
            char c = cs[i];
            int time = 0;
            //如果剩余长度小于等于当前的回文长度了，那么后面就不需要去检查了
            if (cs.length - i < maxLength){
                break;
            }
            while (true){
                time++;
                int targetIndex = getLastCharIndex(c,i,cs,time);
                if (targetIndex == -1){
                    break;
                }
                //如果相同字符中间的长度小于等于当前的最大回文长度，那么后面跳过
                if (targetIndex - i < maxLength){
                    break;
                }
                //判断i到targetIndex中间的字符是否为回文
                if (checkStringIsPalindrome(i,targetIndex,cs)){
                    result = String.valueOf(cs,i,targetIndex-i+1);
                    maxLength =result.length();
                }
            }

        }
        if (result == null){
            return s.substring(0,1);
        }
        return result;
    }

    //检测字符数组在某个闭合区间内是否为回文
    static boolean checkStringIsPalindrome(int start,int end,char[] cs){
        while (start < end){
            char startChar = cs[start];
            char endChar = cs[end];
            if (startChar != endChar){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }


    static int getLastCharIndex(char c, int startIndex,char[] cs,int times){
        int time = 0;
        for (int i = cs.length-1;i>=startIndex;i--){
            if (c == cs[i]){
                time ++;
            }
            if (time == times){
                return i;
            }
        }
        return -1;
    }
}
```