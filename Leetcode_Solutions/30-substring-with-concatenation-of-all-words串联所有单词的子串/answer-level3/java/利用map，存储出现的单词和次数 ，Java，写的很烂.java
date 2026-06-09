class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> ret=new ArrayList<>();
        if(words==null || words.length==0||words.length*words[0].length()>s.length()) return ret;//长度不对，直接返回空
        int allLen=words.length*words[0].length();//总长度
        int singleLen=words[0].length();//单个字符串的长度
        int sLen=s.length();
        //否则判断那么长的距离中，是不是每个字符串都在里面出现了且只出现了一次
        for(int i=0;i<sLen+1-allLen;i++){//如果长度不够，肯定不能再包含所有单词了
            String wordsStr=s.substring(i,i+allLen);//滑动窗口
            if(isStrMatch(s,i,i+allLen,words)){//判断是否匹配
                ret.add(i);
            } 
        }
         return ret;
    }
    private boolean isStrMatch(String s, int start,int end,String[] words){
        String str=s.substring(start,end);
        int singleLen=words[0].length();//单个字符串的长度
        Map<String,Integer> map=new HashMap<>();//存储单词以及出现次数
        for(int i=0;i<words.length;i++){//将数组中都存在map中
            if(!map.containsKey(words[i])){
                map.put(words[i],1);
            }else{
                Integer count=map.get(words[i]);
                map.put(words[i],count+1);
            }
        }
        //进行比对
        for(int j=0;j<str.length();j+=singleLen){
            String newStr=str.substring(j,j+singleLen);
            if(!map.containsKey(newStr)){
                return false;
            }else{
                Integer count2=map.get(newStr);
                map.put(newStr,count2-1);
            }
        }
        for(Integer a:map.values()){
            if(a !=0)return false;
        }
        return true;
    }
}