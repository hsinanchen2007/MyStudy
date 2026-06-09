做的时候没有考虑使用一些现成的算法，而是用直观去求解这个问题，
做完之后看了一下别人的写法，知道排序会更好，但是还是发布一下这个o(n^2)的暴力解法吧
毕竟已经有了快速排序，我们不是照样要学冒泡排序那些“慢速”排序的写法？
```Java []
class Solution {
    public int minimumLengthEncoding(String[] words) {
        
        for (int i = 0;i < words.length;i++) {
            for (int j = i + 1;j < words.length;j++) {
                // 对于一个单词j，如果在前面找到能包含之的单词i，直接舍弃j
                if (contain(words[i],words[j])) words[j] = "";
                // 反之，如果j包含了i。舍弃i，并开始考察i+1的后续单词
                if (contain(words[j],words[i])) {
                    words[i] = "";
                    break;
                }
            }
        }
        // 现在words中多余的单词都已经被舍弃

        // 记录单词长度
        int res = 0;
        // 记录#长度
        int count = 0;
        for (int i = 0;i < words.length;i++) { 
            if (words[i].length()!=0) {
                res += words[i].length();
                count++;
            }
        }

        return res + count;
    }

    // s1（尾）包含了s2
    private static boolean contain(String s1, String s2) {
        int i = s1.length();
        int j = s2.length();
        if (i < j || i == 0 || j == 0) return false;
        while(j>0) {
            if(s1.charAt(--i) == s2.charAt(--j)) ;
            else return false;
        }
        return true;
    }
}
```


