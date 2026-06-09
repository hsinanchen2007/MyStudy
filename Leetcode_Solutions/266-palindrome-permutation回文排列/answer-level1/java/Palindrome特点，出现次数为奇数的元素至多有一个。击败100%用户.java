### Palindrome特点，出现次数为奇数的元素至多有一个。
### Palindrome特点，出现次数为奇数的元素至多有一个。
### Palindrome特点，出现次数为奇数的元素至多有一个。
![Snipaste_2020-04-07_18-18-07.png](https://pic.leetcode-cn.com/264ac0f3510766347671a596b3b828aed1f4bc352d1e295e4d5d853a42e99b53-Snipaste_2020-04-07_18-18-07.png)

### 代码

```java
class Solution {
    public boolean canPermutePalindrome(String s) {
        if(s==null||s.length()==0) return false;
        int[] count=new int[128];
        for(char c:s.toCharArray()) count[c]++;
        boolean oddTwice=false;
        for(int i=0;i<128;i++){   
            if((count[i]&1)==1){
                if(oddTwice) return false;
                oddTwice=true;
            } 
        }
        return true;

    }
}
```