```
class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> res=new ArrayList<Integer>();

        if( (words == null) || (words.length == 0)){return res;}
        int  oneStrLength=words[0].length();
        int  sLength=s.length();
        int wordsSize=words.length;
        int mappingLength=wordsSize*oneStrLength;
        if(sLength==0 && oneStrLength!=0){return res;} 
        if(oneStrLength==0){
            for(int k=0;k<=s.length();k++){
                res.add(k); 
            }
            return res;
        }    


        //计算words集合重复元素次数
        Map<String,Integer> wordsDupMap=new HashMap<String,Integer>();
        for(String str:words){
            Integer oneWordDup=wordsDupMap.containsKey(str)?wordsDupMap.get(str):0;
            wordsDupMap.put(str,oneWordDup+1);  
        }


        //对父字符串进行从左到右的一位位移动
        one:for(int i=0;i<sLength-mappingLength+1;i++){
            Map<String,Integer> wordsCheckDupMap=new HashMap<String,Integer>();   //注意点，应该放在第一次for循环里面
            
            two:for(int j=0;j<wordsSize;j++){
                //注意点，第一次应该是(i,i+1+(oneStrLength-1)),因为两者的长度是两者之间距离+1
                String checkStr=s.substring(i+j*oneStrLength,i+(j+1)*oneStrLength);

                if(!wordsDupMap.containsKey(checkStr)){
                    break;
                }else{
                    Integer num=wordsCheckDupMap.containsKey(checkStr)?wordsCheckDupMap.get(checkStr):0;
                    wordsCheckDupMap.put(checkStr,num+1);
                } 
            }
            if(wordsCheckDupMap.equals(wordsDupMap)){
                res.add(i);
            }  
        }    
            
        return res;
    }
}
```
