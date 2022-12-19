![捕获.PNG](https://pic.leetcode-cn.com/90547310cf1f9f7ee26e8b92262066fc909c40ef4ef55852e115f79ec66a4f69-%E6%8D%95%E8%8E%B7.PNG)

单纯字符串的charAt(),没用split()，用了的话会超13ms，更有甚者会到18ms，而且内存消耗会上37.8MB。我就想知道那些更快，内存更小的答案是什么样的，半天没想出来。


```
class Solution {
    public boolean isValidSerialization(String preorder) {
        if(preorder.charAt(0)=='#'){
            return preorder.length()==1;
        }
        Stack<Character> a=new Stack<Character>();
        int i=0;
        while(i<preorder.length()){
            char qq=preorder.charAt(i);
            if(qq!='#'){
                a.push(qq);
            }else {
                while(a.size()>0&&a.lastElement()=='#'){
                    a.pop();
                    if (a.size()==0)return false;
                    a.pop();
                }
                a.push('#');
            }
            while(i<preorder.length()-1&&preorder.charAt(i+1)!=',')i++;
            i+=2;
        }
        return a.get(0) == '#' && a.size() == 1;
    }
}
```

```
