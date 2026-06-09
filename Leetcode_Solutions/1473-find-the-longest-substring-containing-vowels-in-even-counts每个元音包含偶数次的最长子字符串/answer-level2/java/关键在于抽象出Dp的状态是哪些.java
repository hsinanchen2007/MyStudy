```
class Solution {
    public int findTheLongestSubstring(String s) {
        //子串，滑动窗口，前缀树，双指针，哈希
        //bit位记录五个字母的统计情况，相同的两个之间相减就符合条件，最长只需要记录下状态最开始的那个，和结束的那个
        HashMap<Integer,Integer> map=new HashMap<>();
        int record=0;
        map.put(0,-1);
        int res=0;
        for(int i=0;i<s.length();i++){
            char c=s.charAt(i);
            if(c=='a'){
                record^=1;
            }else if(c=='e'){
                record^=1<<1;
            }else if(c=='i'){
                record^=1<<2;
            }else if(c=='o'){
                record^=1<<3;
            }else if(c=='u'){
                record^=1<<4;
            }
            if(map.containsKey(record)){
                res=Math.max(res,i-map.get(record));
            }else{
                map.put(record,i);
            }
        }
        return res;
    }
}
```
