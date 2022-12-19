因为我学KMP的时候，就真的理解了很久，这次贴出来希望对你有所帮助，欢迎交流。
```
 public String longestPrefix(String s) {
        if(s.length() < 2) return "";
        char[] chars =  (s + s.charAt(s.length()-1)).toCharArray();
        int[] next = new int[s.length() + 1];
        int[] next = new int[s.length()];//求每一个字段之前最长前缀和后缀匹配的长度
        int cur = 2;
        next[0] = -1;//0位置最长前缀长度为-1
        next[1] = 0;//1位置最长前缀长度为0
        int cn = 0;//表示前面一个数字(不包括自身)的前缀的末尾索引的后面一位
        while(cur < next.length){
            if(chars[cur-1] == chars[cn]){
                next[cur++] = ++cn;//前缀长度[0..cn]，后缀为[x...cur-1].
            }else if(cn > 0){//chars[cn]不能加入到前缀中，chars[cur-1]不能加入到后缀中，寻找当前cn位置的最长前缀，更新cn,继续循环判断是否将chars[cur-1]加入当前前缀对应的后缀中
                cn = next[cn];
            }else{
                next[cur++] = 0;//cn < 0，来到索引为0的位置，说明chars[cur]前面的字符串不存在前缀和后缀匹配的情况
            }
        }
        return s.substring(0, next[chars.length-1]);
    }
```
附上一张小图
![next.png](https://pic.leetcode-cn.com/b199e2d60ec69807be46422154519e6105b3a942f9764a9cbed8d30817552cd8-next.png)
