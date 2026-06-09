![image.png](https://pic.leetcode-cn.com/80fd9f48aaa8ed6b98d5061b7da3770babeab23edf42c190a06652467927b957-image.png)
```
class Solution {
        /**
         * 最多删除一个字符，判断是否能成为回文串
         * 思路：双指针i和j，
         * 当遇到不相等字符的时候，采用删除i所指字符或者删除j对应字符，如果两种方法都不行，返回false
         * @param s
         * @return
         */
        public boolean validPalindrome(String s) {
            int i=0,j=s.length()-1;
            while (i<j){
                while (i<j && s.charAt(i)==s.charAt(j)){
                    i++;
                    j--;
                }
                //当第一次遇到不相等的时候
                if (i<j && s.charAt(i)!=s.charAt(j)){
                    int tempi=i;
                    int tempj=j;
                    i++;//删除i字符
                    while (i<j && s.charAt(i)==s.charAt(j)){
                        i++;
                        j--;
                    }
                    //当删除i字符遇到不相等的时候，尝试回到第一次不等的位置，删除j字符
                    if (i<j && s.charAt(i)!=s.charAt(j)) {
                        i=tempi;
                        j=tempj;
                        j--;//删除j字符
                        while (i<j && s.charAt(i)==s.charAt(j)){
                            i++;
                            j--;
                        }
                        if (i<j && s.charAt(i)!=s.charAt(j))
                            return false;
                    }

                }
            }
            return true;
        }
    }
```
