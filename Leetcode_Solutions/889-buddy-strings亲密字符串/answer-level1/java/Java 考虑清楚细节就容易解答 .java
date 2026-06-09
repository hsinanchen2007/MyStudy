![2020032501.PNG](https://pic.leetcode-cn.com/445fc5846cfd004e86b173f1b84e8ca9c3b6acb4627880d85ff4ab3179dadd65-2020032501.PNG)

### 解题思路
思路:
情况一: 

-当字符串A和B的长度不相等, 直接返回false;

情况二--当字符串A和B的内容相等, 只需要遍历一遍字符串A:

-遍历字符串A, 判断字符串A中是否存在一个小写字母出现的次数大于或等于2,

-若存在, 返回true, 否则, 返回false;  

情况三--当字符串A和B的内容不相等:

-声明数组cnt记录26个小写字母出现的次数, 数组cnt的索引代表相应的小写字母

-声明int型的变量diffCnt, 记录字符串A和B中相同索引位置但字母不同的次数

-当出现字符串A和B在相同索引位置的值不同时, 声明index1记录字符串A中的字母对应到数组cnt中的索引

-声明index2记录字符串B中的字母对应到数组cnt中的索引

-当出现diffCnt的值大于2, 则直接返回false;

-遍历完成后, 再来判断索引index1和index2在数组cnt中的值是否为0;

-当在cnt[index1], cnt[index2]的值中, 存在任意一个值不为0, 则返回false;

-否则返回true;

### 代码

```java
class Solution {
    public boolean buddyStrings(String A, String B) {
        int[] cnt = new int[26];
        if(A.length()!=B.length()){
            return false;
        }
        //两个字符串内容相等
        if(A.equals(B)){
            for(int i=0;i<A.length();i++){
                cnt[A.charAt(i)-'a']++;
                if(cnt[A.charAt(i)-'a']>=2){
                    return true;
                }
            }
            return false;
        }
        //两个字符串内容不相等
        int diffCnt = 0;
        int index1 = 0;
        int index2 = 0;
        for(int i=0;i<A.length();i++){
            if(A.charAt(i)!=B.charAt(i)){
                diffCnt++;
                index1 = A.charAt(i)-'a';
                index2 = B.charAt(i)-'a';
            }
            if(diffCnt>2){
                return false;
            }
            cnt[A.charAt(i)-'a']++;
            cnt[B.charAt(i)-'a']--;
        }
        
        if(cnt[index1]!=0||cnt[index2]!=0){
            return false;
        }

        return true;
    }
}
```