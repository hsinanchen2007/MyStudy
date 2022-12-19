```
class Solution {
    //将排列转化为窗口内的字符串次数
    //用数组统计字符出现次数。如果在窗口内，字符出现次数相同，即含有排列
    public boolean checkInclusion(String s1, String s2) {
       if(s1.length() > s2.length())
           return false;
        //在s2中使用一个和s1长度相同的数组，统计窗口内出现次数
        int[] dict1 = new int[26];
        int[] dict2 = new int[26];
        for(int i = 0; i < s1.length(); i++){
            dict1[s1.charAt(i) - 'a']++;
            dict2[s2.charAt(i) - 'a']++;
        }
        //判断s2中第一个窗口是否满足, 对第一个单独判断
        if(match(dict1,dict2))
            return true;
        //第一个不满足，对s2上的窗口进行滑动
        for(int i = 0, j = s1.length(); j < s2.length(); i++,j++){//i为左端，j为右端,因为要保证长度不变，所以同时移动
            dict2[s2.charAt(i)-'a']--;
            dict2[s2.charAt(j)-'a']++;
            if(match(dict1,dict2))
                return true;
            
        }
        return false;
        
    }
    private boolean match(int[] dict1, int[] dict2){
        for(int i = 0; i < dict1.length; i++){
           if(dict1[i] != dict2[i])
               return false;
        }
        return true;
    }
}
```
