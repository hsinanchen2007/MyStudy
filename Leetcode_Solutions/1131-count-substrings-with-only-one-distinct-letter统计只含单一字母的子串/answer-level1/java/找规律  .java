### 解题思路
字符串   子集类型      子集数   
a           a               1 
aa          a aa            3=2+1            =1+2
aaa         a aa aaa        6=3+2+1          =3+3
aaaa                        10=4+3+2+1       =6+4
                          显然是一个等差数列   不用公式的话就是之前的总和+之前总和元素中最大数+1
 然后如果不匹配 如ab 就从头来且子集数+1
### 代码

```java
class Solution {
    public int countLetters(String S) {
        int counter =1; //同字母最大子集长度计数器
        int counterall =1;//总数
        for(int i=0;i<S.length()-1;i++){
            if(S.charAt(i) == S.charAt(i + 1)){
              counterall=counterall+counter+1;
              counter++;
            }
            else{
             counter =1;
             counterall++;
            }
        }
     
           return counterall;
           }
    }

```