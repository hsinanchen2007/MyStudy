### 解题思路
此处撰写解题思路
偶数次数字母首尾对应，可出现一个奇数个（在正中间）


记录所有的52个字母 创建int数组记录他们分别出现的次数 偶数个直接相加 奇数个减一再相加 若出现一次奇数个的字母
则需要再加一
### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        char[] letters = {'a','b','c','d','e','f','g',
                            'h','i','j','k','l','m','n','o',
                            'p','q','r','s','t','u','v','w','x','y','z',
                            'A','B','C','D','E','F','G',
                            'H','I','J','K','L','M','N','O',
                            'P','Q','R','S','T','U','V','W','X','Y','Z'};
        int[] count = new int[52];
        for(int i=0;i<s.length();i++){
            for(int j=0;j<letters.length;j++){
                if(s.charAt(i)==letters[j]){
                    count[j]++;
                }
            }
        }
        int len = 0;
        int countOdd = 0;
        for(int k=0;k<count.length;k++){
            if(count[k]%2==0){
                len += count[k];
            }
            else{
                countOdd =1;
                len += count[k]-1;
                
                
            }
        }

        //System.out.println(isPalindrome("abcCBba"));
        return len+countOdd;

    }
   
  
}

```