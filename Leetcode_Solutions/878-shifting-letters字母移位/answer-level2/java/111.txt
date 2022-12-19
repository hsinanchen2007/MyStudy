### 解题思路
反过来遍历chars数组,最后一个字符肯定只加一次,当前遍历之前的字符肯定都会和当前正在遍历的那个加上相同的值,这样想就很好理解了.这样做起来比较简单但是速度有点变,毕竟用了双层循环,时间复杂都是都是n平方了

### 代码

```java
class Solution {
    public String shiftingLetters(String S, int[] shifts) {
        //把字符串s转化成字符数组
        char []chars = S.toCharArray();
        int num = 0;
        //循环shifts
        for (int i=chars.length-1;i>=0;i--){
            num = shifts[i]%26;
            chars[i] = (char) ((chars[i]+num-97)%26+97);
            for(int j=i-1;j>=0;j--){
                chars[j] = (char) ((chars[j]+num-97)%26+97);
            }
        }

        return String.valueOf(chars);
    }
}
```