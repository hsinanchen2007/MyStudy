### 解题思路
新手开写。
一眼上来思路是linkedhashmap；先存<char,int>,然后linkedhashmap有序，遍历即可。
但是印象里类似题都是可以用数组代替hashmap的，所以用了数组存入数据。发现用数组后直接遍历数组，得出的是按字典顺序的第一个单独字符，
于是就想者从字符串遍历出第一个在对应的数组位置值为1的那个字符y即可。

### 代码

```java
class Solution {
    public char firstUniqChar(String s) {
        if(s==null||s.length()==0)
            return ' ';
        int nums[] = new int[26];
        for(int i=0;i<s.length();i++){
            char a = s.charAt(i);
            nums[a-'a']++;
        }
        for(int i=0;i<s.length();i++){
            char a = s.charAt(i);
            if(nums[a-'a']==1){
                return a;
            }
        }
        
        return ' ';

    }
}
```