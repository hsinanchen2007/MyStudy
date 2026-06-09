读题可知，是一个字符串数组，求最长公共子串
所以，第一反应想到，用第一个字符串中各字符去与后面的对应比较即可
public String longestCommonPrefix(String[] sts){
  //为空判断
   if (strs.length == 0 || strs == null) return "";
  //遍历对比
   for(int i = 0;i < strs[0].length;i++) { //遍历数组中第一个元素
       char c = strs[0].charAt(i); //定义变量，接收第一个元素的第一个字符
       for (int j = 1;j < strs.length;j++) { //遍历整个数组
            //判断后一个元素中同位字符是否相等，且后面元素如果长度和第一个元素长度相等时，停止比较
            if (i == strs[j].length || strs[j].charAt(i) != c){ 
                return strs[0].substring(0,i);
            }
        }
    }
    return strs[0];
    }
}