### 解题思路

使用HashMap 辅助，这个没什么好说的

我主要想写的是，再char出现的次数 >= 2的时候，其实再将次数 +1 再put 进去，已经没有必要

2次和3次100次对我们的意义是一样的

### 代码

```java
class Solution {
    public char firstUniqChar(String s) {
        if(s == null || s.length() == 0){
            return ' ';
        }

        HashMap<Character,Integer> map = new HashMap<>();

        for(int i = 0;i< s.length();i++){
            char c = s.charAt(i);
            if(map.get(c) != null){
                int nums = map.get(c);
                //在次数超出 1 次之后，nums 再增加没意义，干脆节省一次put操作
                if(nums <= 1){
                    map.put(c, nums + 1);
                }
            }else{
                map.put(c,1);
            }
        }

        for(int i = 0;i< s.length();i++){
            char c = s.charAt(i);
            if(map.get(c) == 1){
                return c;
            }
        }

        return ' ';

    }
}
```