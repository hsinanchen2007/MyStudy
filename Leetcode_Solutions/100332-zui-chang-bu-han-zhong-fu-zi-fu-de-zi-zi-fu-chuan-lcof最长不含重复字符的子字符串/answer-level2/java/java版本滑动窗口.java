#### 解题思路
1、用一个之指针记录滑动窗口的起点
2、判断滑动窗口内是否包含当前值
* 如果包含，就将头指针移动到当前指针位置处
注意：通过HashMap判断的注意滑动窗口的起始位置

#### 代码
```
 public int lengthOfLongestSubstring(String s) {
        int left = 0;
        if(s.length() == 0) return 0;
        int max = 0;
        HashMap<Character,Integer> map = new HashMap<>();
        for(int i = 0;i < s.length();i++){
            char ch = s.charAt(i);
            //说明已经存在
            if (map.containsKey(ch)){
                //只找窗口内是否包含该值
                 if(map.get(ch) +1 > left)
                    left = map.get(ch) +1;
            }
                map.put(ch,i);
            if(max < i + 1 - left)
                max = i + 1 - left;
        }
        return max;
    }
```
