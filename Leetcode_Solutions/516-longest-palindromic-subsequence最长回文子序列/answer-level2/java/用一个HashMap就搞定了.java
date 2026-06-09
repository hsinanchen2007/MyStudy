 
map来统计所有字母重复的个数，然后for循环打印最大的子串就可以了
这样看算法时间复杂度o(n)
 public int longestPalindromeSubseq(String s) {
        HashMap<Character,Integer> map =new HashMap();
        char[] chas=s.toCharArray();
        for(int i=0;i<chas.length;i++){
            if(map.containsKey(chas[i])){
                map.put(chas[i],map.get(chas[i]).intValue()+1);
            }else{
                map.put(chas[i],1);
            }
        }
        
        int max=1;
        for (Integer value : map.values()) {

            if(value.intValue()>max){
                max=value.intValue();
            }
        }

        return max;
    }