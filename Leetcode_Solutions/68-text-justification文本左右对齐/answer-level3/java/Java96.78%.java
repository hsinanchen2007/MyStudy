所有的思路在注释里。

```

/*
 * @Website: https://ntutn.top
 * @Date: 2019-11-24 00:32:42
 * @LastEditors: zero
 * @LastEditTime: 2019-11-24 11:01:47
 * @Description: 文本左右对齐
 * @FilePath: /.leetcode/68.文本左右对齐.java
 */
import java.util.LinkedList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=68 lang=java
 *
 * [68] 文本左右对齐
 */

// @lc code=start
class Solution {
    private String getNormalLine(List<String> words,int maxWidth,int lineRes){
        if(words.size()==1){
            //只有一个单词，和最后一行一样处理
            return getLastLine(words, maxWidth, lineRes);
        }
        //计算每个空位应该插入的空格数
        int insertSpaces=1+lineRes/(words.size()-1);
        //剩余的空格数
        int spaceRes=lineRes-(insertSpaces-1)*(words.size()-1);
        StringBuilder sb=new StringBuilder();
        boolean flag=false;
        for (String word : words) {
            if(flag){
                for (int i = 0; i < insertSpaces; i++) {
                    sb.append(' ');
                }
                if(spaceRes>0){
                    sb.append(' ');
                    spaceRes--;
                }
            }else{
                flag=true;
            }
            sb.append(word);
        }
        return sb.toString();
    }

    private String getLastLine(List<String> words,int maxWidth,int lineRes){
        StringBuilder sb=new StringBuilder();
        boolean flag=false;
        for (String word : words) {
            if(flag){
                sb.append(' ');
            }else{
                flag=true;
            }
            sb.append(word);
        }
        for (int i = 0; i < lineRes; i++) {
            sb.append(' ');
        }
        return sb.toString();
    }

    public List<String> fullJustify(String[] words, int maxWidth) {
        //最终输出结果
        List<String> res=new LinkedList<>();
        //当前行包含的所有单词
        List<String> lineWords=new LinkedList<>();
        //当前行剩余的空位
        int lineRes=maxWidth;
        for (String word : words) {
            //第一个单词占用len(word)个位置，其他单词占用len(word)+1个位置
            int wLength=lineWords.isEmpty()?word.length():(word.length()+1);
            if(lineRes>=wLength){
                lineRes-=wLength;
                lineWords.add(word);
            }else{
                //当前行放不下当前单词，将当前行送入计算并清空
                res.add(getNormalLine(lineWords, maxWidth,lineRes));
                lineWords.clear();
                //因为行清空，当前单词是第一个单词，少占用一个空格
                wLength--;
                //放入第一个单词
                lineRes=maxWidth-wLength;
                lineWords.add(word);
            }
        }
        //处理最后一行
        if(!lineWords.isEmpty()){
            res.add(getLastLine(lineWords, maxWidth,lineRes));
        }
        return res;
    }
}
// @lc code=end


```

Accepted
- 27/27 cases passed (1 ms)
- Your runtime beats 96.78 % of java submissions
- Your memory usage beats 32.47 % of java submissions (35.1 MB)