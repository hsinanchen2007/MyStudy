### 解题思路

暴力统计每个字母个数
### 代码

```java
class Solution {
    /*
    'A' : Absent，缺勤
    'L' : Late，迟到
    'P' : Present，到场 */
    //如果一个学生的出勤记录中不超过一个'A'(缺勤)并且不超过两个连续的'L'(迟到),那么这个学生会被奖赏。
    public boolean checkRecord(String s) {
        char []  charlist = s.toCharArray();
        int acout = 0 , lcout = 0 ;
        for (char test: charlist){
            if('A'== test) acout++;
            if('L'== test){
                lcout++;
                if(lcout>2) return  false ;
            }else{
                lcout = 0 ;
            }
        }
        if(acout>1) return false;
        return true ;
    }
}
```