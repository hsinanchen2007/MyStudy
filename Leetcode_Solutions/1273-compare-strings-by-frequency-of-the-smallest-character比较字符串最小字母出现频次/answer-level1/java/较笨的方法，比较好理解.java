由于循环较多，比较耗时
方法：将字符串数组queries中的每一字符串分别与另一字符串数组words中的所有字符串依次比较，输出结果。

class Solution {
    public int[] numSmallerByFrequency(String[] queries, String[] words) {
        //若有一字符串数组为空，直接返回
        if(queries == null || words == null)
            return null; 

        int[] cnt = new int[queries.length];
        for(int i = 0;i < queries.length;i++){
            for(int j = 0;j < words.length;j++){
                if(Count(queries[i]) < Count(words[j])){
                    cnt[i] += 1;
                }
            }
        }
        return cnt;
    }

    public int Count(String s){
        int res = 0;
        char min = s.charAt(0);
        //找到the smallest character
        for(int i = 0;i < s.length();i++){
            if(s.charAt(i) < min){
                min = s.charAt(i);
                res = 0;
            }
        //统计the smallest character出现次数
            if(s.charAt(i) ==min){
                res++;
            }
        }
        return res;
    }
}

欢迎批评指正~~