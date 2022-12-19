```
class Solution {
    public List<String> generatePossibleNextMoves(String s) {
        List<String> result = new ArrayList<String>();
        int len = s.length();
        String res = new String("");
        for(int i=1;i<len;i++){
            //匹配的位置是i-1和i
            if(s.charAt(i-1)=='+' && s.charAt(i)=='+'){
                if(i-1 == 0){//前两个为'+'避免越界
                    res = "--" + s.substring(2,len);
                    result.add(res);
                    continue;
                }
                if(i-1 == len-2){//末尾两个为'+'避免越界
                    res = s.substring(0,len-2) + "--";
                    result.add(res);
                    continue;
                }
                res = s.substring(0,i-1) +"--" + s.substring(i+1,len);
                result.add(res);
            }
        }
        return result;
    }
}
```
