三行搞定,执行用时0ms，击败100%java用户
public int lengthOfLastWord(String s) {
        //去掉尾部空格
        s = s.trim();
        //返回空格在指定字符串中最后一次出现的索引位置
       int index = s.lastIndexOf(" ");
       //字符串长度-索引-1 = 最后一个空格长度 
       return s.length() - index - 1;
    }