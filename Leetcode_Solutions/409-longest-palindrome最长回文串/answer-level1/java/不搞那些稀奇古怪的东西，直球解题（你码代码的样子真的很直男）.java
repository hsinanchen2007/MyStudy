### 解题思路
因为刚刚开始学JAVA，啥玩意都不会.....
说白了就是求一个字符串里面有多少个对子，老牌友应该都懂.....
具体写注释里面了（可能废话有些多)
### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        final int N = 26;
        int[] Capital = new int[N];  //放字符串里面的大写字母
        int[] Lower = new int[N];    //同理，放小写字母的地方
        char[] Loge = new char[s.length()];  //将字符串拆分成单个字符
        int counst = 0,Fia = 0; //counst是计数器，Fia是提交值

        Loge = s.toCharArray();  //拆分嘛，都懂的

        //区分大小写，都懂的
        for(int i=0;i<s.length();i++){
            if(Loge[i] >= 'A' && Loge[i] <= 'Z')
                Capital[Loge[i] - 'A']++;
            if(Loge[i] >= 'a' && Loge[i] <= 'z')
                Lower[Loge[i] - 'a']++;
        }

        //看看这个字符串的长度是奇是偶
        if(s.length() % 2 == 0){
            //找对子
            for(int i=0;i<N;i++){
                if(Capital[i] >= 2)
                    counst = counst + Capital[i] / 2;
            }
            for(int i=0;i<N;i++){
                if(Lower[i] >= 2)
                    counst = counst + Lower[i] / 2;
            }
            //求最终长度，如果 对子数量*2 和 字符串长度相等 说明这个字符串里面一个单张都没有（大家都获得了幸福）
            //直接输出去就行（没有中间字符）
            //如果对子数量*2 和 字符串长度对不上，因为字符串的长度是偶数，说明至少有两个单张
            //输出时对子长度*2 + 1就行（回文串的中间字符）
            if(counst * 2 == s.length())
                Fia = s.length();
            else
                Fia = counst * 2 + 1;
        }
        else{
            //和偶数时一样，先找对子
            for(int i=0;i<N;i++){
                if(Capital[i] >= 2)
                    counst = counst + Capital[i] / 2;
            }
            for(int i=0;i<N;i++){
                if(Lower[i] >= 2)
                    counst = counst + Lower[i] / 2;
            }
            //因为字符串的长度是奇数，无论如何绝对会有至少一张单张（总有一人注孤生）
            //最好的情况就是只有一个单张，此时最长的回文就是字符串本身（那个单身的就是那个中间字符）
            //如果单张不止一个的话，随便找个单张当中间字符输出总长就好
            if(counst * 2 + 1 == s.length())
                Fia = s.length();
            else
                Fia = counst * 2 + 1;
        }


        System.out.println(Fia); 
        //最后的打印Fia和这么多的空行是我个人的恶趣味，不用理会......
        return Fia;
    }
}
```