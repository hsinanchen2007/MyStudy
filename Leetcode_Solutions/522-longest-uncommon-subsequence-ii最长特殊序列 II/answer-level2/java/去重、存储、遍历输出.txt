思路：先去除重复的，再用一个数组存储不重复的，判断每一个是否是原字符串数组中的任意一项的子数组，这里要注意，判断的时候要找比自己长度长的，因为不可能是短的子序列，和自己一样的也不行，因为自己就是自己的子序列。
```
public static int findLUSlength(String[] strs) {
        HashMap<String, Integer> map = new HashMap<>();
        //用map存储相同的，直接把相同的除去
        for (int i = 0; i < strs.length; i++) {
            if(map.containsKey(strs[i])){
                map.put(strs[i],map.get(strs[i])+1);
            }else{
                map.put(strs[i], 1);
            }
        }
        //存储不重复的
        String string[] = new String[50];
        //计数不重复的
        int count = 0;
        for (Map.E***y<String, Integer> e***y : map.e***ySet()) {
            //去除重复的
            if(e***y.getValue()<2){
                string[count++] = e***y.getKey();
            }
        }
        //长度
        int len = 0;
        //表示全部重复
        if(count == 0){
            return -1;
        }else{
            //超过一个元素的，一个个判断，
            for (int i = 0; i < count; i++) {
                //是子集，直接跳过
                if(isSub(strs,string[i])){
                    continue;
                }else{
                    //不是子集，选择最大的长度
                    len = Math.max(len,string[i].length());
                }
            }
        }
        return len == 0 ? -1 : len;
    }
    /*
        判断是否包含子集，因为涉及到元素的删除之后只要相对顺序
        保持不变还是会算过子集，所以需要一位位判断
     */
    private static boolean containsSub(String s,String p){
        int i,j;
        for(i=0,j=0;i<p.length()&&j<s.length();j++) {
            if (s.charAt(j) == p.charAt(i)) {
                i++;
            }
        }
        if (i >= p.length()) return true;
        return false;
    }
    private static boolean isSub(String[] strs, String s){
        for (int i = 0; i < strs.length; i++) {
            //如果字符串数组中子元素长度小于需要比较的直接跳过
            if(s.length() < strs[i].length() && containsSub(strs[i],s)){
                return true;
            }
        }
       return false;
    }
```