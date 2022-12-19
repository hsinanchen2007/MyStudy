执行用时 : 27 ms, 在Longest Word in Dictionary的Java提交中击败了77.05% 的用户
内存消耗 : 44 MB, 在Longest Word in Dictionary的Java提交中击败了78.46% 的用户
```
class Solution {
    public String longestWord(String[] words) {
        if(words.length==1){//先判断特殊用例
            if(words[0].length()==1){
                return words[0];
            }
            else{
                return "";
            }
        }
        Arrays.sort(words);//排序
        int len = 0;
        for(int i=0; i<words.length; i++){
            len = Math.max(len,words[i].length());//获取最长字符串长度
        }
        for(int i=len; i>=1; i--){//用最长长度开始扫描
            int pos = 0;
            for(int j=0; j<words.length; j++){
                if(words[j].length()==i){//如果当前字符串长度与最外层循环长度相等
                    pos = j;
                    int temp = i;
                    for(int k=j-1; k>=0; k--){
                        if(words[j].substring(0,temp-1).equals(words[k])){//每次判断减少一个字母是否吻合
                            temp--;
                        }
                    }
                    if(temp==1){//最后剩一个字母
                        return words[j];
                    }
                }
            }
        }
        return "";
    }
}
```