![奇怪的知识增加了.jpg](https://pic.leetcode-cn.com/b9eaf02f9e61d55c708747121fc4eb4c18a80f466d89497b1da42533fddfb07a-%E5%A5%87%E6%80%AA%E7%9A%84%E7%9F%A5%E8%AF%86%E5%A2%9E%E5%8A%A0%E4%BA%86.jpg)

### 代码

```java
class Solution {
    public String[] permutation(String s) {
        if (s.length() == 1) {
            return new String[]{s};
        }
        String[] tmp = permutation(s.substring(1));
        String[] res = new String[tmp.length * s.length()];
        for (int i = 0; i < tmp.length; i++) {
            //交换操作
            //不交换，与第一个交换，与第二个交换
            res[i * s.length()] = s.charAt(0) + tmp[i];
            for (int j = 0; j < s.length() - 1; j++) {
                res[i * s.length() + j + 1] = tmp[i].charAt(j) + tmp[i].substring(0, j) + s.charAt(0) + tmp[i].substring(j + 1);
            }
        }
        Set<String> set = new HashSet<String>();
        for(String str : res){
            set.add(str);
        }
        String[] finRes = new String[set.size()];
        int i = 0;
        for(String str: set){
            finRes[i++] = str;
        }
        return finRes;
    }
}
```