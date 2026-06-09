审完题就觉得这道题应该不难做，但是绝对很麻烦。毕竟看着就是那种判断来判断去的。初步一看判断数组中每个字符串的每个字符就已经是双层循环了。。还有细节处理，啧啧。
咳咳，这里其实可以用统一小写的，但是我直接在给定字符串就大小写都算上了，其实我想的是先做出来如果性能不行再优化，但是直接0ms就不优化了。
思路就是判断一个字符串的第一个单词属于哪一行的，接下来照着这行判断，出现这行不存在的直接break。都判断完了没有不是的加到结果集中。
因为一开始不知道结果集多长所以创建的数组和给定数组长度一样，再遍历一遍使得结果集大小正好。

```
class Solution {
    public String[] findWords(String[] words) {
        String[] res = new String[words.length];
        String fir = "qwertyuiopQWERTYUIOP";
		String sec = "asdfghjklASDFGHJKL";
		String tir = "zxcvbnmZXCVBNM";
        int k = 0;
        for(int i = 0;i<words.length;i++){
            String temp = "";
            for(int j = 0;j<words[i].length();j++){
                if(fir.indexOf(words[i].charAt(0))!=-1){
                    temp = fir;
                }else if(sec.indexOf(words[i].charAt(0))!=-1){
                    temp = sec;
                }else{
                    temp = tir;
                }
                if(temp.indexOf(words[i].charAt(j))==-1){
                    break;
                }
                if(temp.indexOf(words[i].charAt(j))!=-1&&j==words[i].length()-1){
                    res[k]=words[i];
                    k++;
                }
            }
        }
        String[] result = new String[k];
        for(int p = 0;p<k;p++){
            result[p] = res[p];
        }
        return result;
    }
}
```
