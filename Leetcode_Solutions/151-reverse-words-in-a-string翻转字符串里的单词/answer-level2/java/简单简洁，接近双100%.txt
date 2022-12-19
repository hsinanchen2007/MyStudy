![image.png](https://pic.leetcode-cn.com/a5b9d98bfb42dba6b12634cb7b8bdd19006462055a200c9dc2ba0eb8711bd086-image.png)

如果不用StringBuilder改用ans+的话会慢很多很多。。。
```
class Solution {
    public String reverseWords(String s) {
        String [] str = s.split(" ");
        StringBuilder ans = new StringBuilder();
        for (int i = str.length - 1; i >= 0; i--){
            if (str[i].equals("")){
                continue;
            }
            ans.append(str[i]).append(" ");
        }
        
        return ans.toString().trim();
    }
}
```
