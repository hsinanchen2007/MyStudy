思路：先按照“\n”拆分成数组，按照\t寻找层级关系，利用临时变量保存一个一个完整的文件路径（最后一级是文件夹的，直接清空临时变量），临时变量和之前记录的完整文件路径进行大小对比。ps：提交时候输入路径会出现/t用空格表示，记得提前替换）
```
class Solution {
    public int lengthLongestPath(String input) {
        input = input.replace("\n    ","\n\t");
        //增加/路径，方便后面计算字符串大小
        input = input.replace("\n\t","/\n\t");
        String[] strs = input.split("\n");
        int t_count = 0;
        String tempStr = "",theBestLongStr = "";
        for(int i=0;i< strs.length;i++){
            int now_t_count = strs[i].length() -  strs[i].replace("\t","").length();
            if(now_t_count > t_count || now_t_count == 0){
                tempStr = now_t_count > t_count ? tempStr + strs[i]:strs[i];
            } else {
                String t_str = "";
                for(int j=1; j<=now_t_count;j++){
                    t_str += "\t";
                }
                String[] arg = tempStr.split(t_str);
                tempStr = arg[0] + strs[i];
            }
            //只有文件路径会被记录下来
            if(strs[i].contains(".")){
                if(tempStr.endsWith("/")){
                    tempStr = tempStr.substring(0,tempStr.length() - 1);
                }
                if(theBestLongStr.equals("") || tempStr.replace("\t","").length() > theBestLongStr.replace("\t","").length()){
                    theBestLongStr = tempStr;
                }
            }
            t_count = now_t_count;
        }
        //最后一个文件路径对比
        tempStr = tempStr.replace("\t","");
        theBestLongStr = theBestLongStr.replace("\t","");
        if(tempStr.contains(".") && tempStr.length() > theBestLongStr.length()){
            return tempStr.length();
        }
        return theBestLongStr.length();
    }
}
```
