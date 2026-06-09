首先用哈希表 tHash 统计出 t 中所有字符出现的次数
然后我们用两个指针 left，right 来扫描整个字符串，同时用一个哈希表 sHash 统计 left—right 之间每种字符出现的次数，每次遍历需要的操作如下：
1. 更新哈希表sHash 
2. 检查s.charAt(left)是否多余，如果是，则移除且更新 left
3. 检查当前窗口是否已经满足 t  中所有字符，如果是，则更新答案

```
    public String minWindow(String s, String t) {
        int count = 0, left = 0, right = 0, tcount = t.length();
        int[] tHash = new int[128], sHash = new int[128];
        int len = Integer.MAX_VALUE, minLeft = 0;
        
        for(char val : t.toCharArray()){
            tHash[val] ++ ;
            if(tHash[val] > 1) tcount --;
        }
        
        for(char val : s.toCharArray()){
            sHash[val] ++ ;
            if(sHash[val] == tHash[val]) count ++;
            
            while (left <= right && sHash[s.charAt(left)] > tHash[s.charAt(left)]) {
                sHash[s.charAt(left)] -- ;
                left ++ ;
            }
            
            if(count >= tcount){
                int temp = right - left + 1;
                if(temp < len){
                    minLeft = left;
                    len = temp;
                }
            }
            right ++;
        }
        
        if(len != Integer.MAX_VALUE) 
            return s.substring(minLeft, len + minLeft);
        else
            return "";
    }
```