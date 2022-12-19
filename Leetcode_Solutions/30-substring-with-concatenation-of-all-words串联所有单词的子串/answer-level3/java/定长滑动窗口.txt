### 解题思路
留下了没技术的眼泪
![微信截图_20200305221833.png](https://pic.leetcode-cn.com/6fd177b4a1a954400f4f87466736a955ec6b207138aac88d64a62286d6f632cf-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200305221833.png)

### 代码

```java
class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        HashMap<String,Integer> need = new HashMap<String,Integer>();
        
        List<Integer> ans = new ArrayList<Integer>();
        int lenW = words.length, lenS = s.length();
        if(lenS == 0 || lenW == 0)
            return ans;
        //步长
        int step = words[0].length();
        //窗口定长
        int left = 0, right = step * lenW;
        for(int i = 0; i < lenW; i++){
            String tmpStr = words[i];
            need.put(tmpStr, need.getOrDefault(tmpStr, 0) + 1);
        }
        //定长窗口右移
        while(right <= lenS){
            int match = 0;
            HashMap<String,Integer> window = new HashMap<String,Integer>();
            //统计窗口内的
            for(int i = left; i < right; i += step){
                String tmpStr = s.substring(i, i + step);
                window.put(tmpStr, window.getOrDefault(tmpStr, 0) + 1);
                if(need.containsKey(tmpStr) && need.get(tmpStr) == window.get(tmpStr)){
                    match++;
                }
            }
            //匹配成功
            if(match == need.size()){
                ans.add(left);    
            } 
            left++;
            right++;
        }
        return ans;
    }
}
```