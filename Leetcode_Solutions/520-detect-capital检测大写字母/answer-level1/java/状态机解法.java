
a :S0
A :S1
aa:S0
AA:S2
Aa:S0
aA:S3
AAa:S3
AAA:S2

如果大家理解有限状态机的话就明白我写的啥了，可以画个状态转移图看看。
执行用时 :2 ms, 在所有 Java 提交中击败了97.93%的用户
内存消耗 :35.5 MB, 在所有 Java 提交中击败了92.08%的用户

```java
class Solution {
    public boolean detectCapitalUse(String word) {
        
        int state = 0;
        if(word.charAt(0)>= 'A' && word.charAt(0) <= 'Z')
        {
            state = 1;
        }
        for(int i=1; i<word.length(); i++){
            if(word.charAt(i) >= 'a' && word.charAt(i)<='z'){
                switch(state){
                    case 0: state = 0;break;
                    case 1: state = 0;break;
                    case 2: state = 3;break;
                    default: break;        
                }
            }
            if(word.charAt(i) >= 'A' && word.charAt(i) <= 'Z'){    
                switch(state){
                    case 0: state = 3;break;
                    case 1: state = 2;break;
                    case 2: state = 2;break;
                    default: break;  
                }  
            }
            
            if(state == 3){
                return false;
            }   
        }
        return true;
    }
}
![image.png](https://pic.leetcode-cn.com/d54c6f94ee24cff40ca99542716209753ebcaad39e77074a743d5e15bb6bbabc-image.png)

```