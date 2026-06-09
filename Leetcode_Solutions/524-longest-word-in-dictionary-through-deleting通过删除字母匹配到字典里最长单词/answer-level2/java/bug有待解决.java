### 解题思路
下面的代码不知道问题出在了哪儿


### 代码

//记录下，这个程序可能是对的，但是有小bug
class Solution {
    public String findLongestWord(String s, List<String> d) {
        String target="";  //定义一个目标空字符串，最后做返回值
        int i=0,j=0;
        for(String str:d){ // *******这是遍历这种字符型字典常用的手法**********
            while(i<s.length() && j<str.length()){
                if(str.charAt(i)==s.charAt(j)){
                    i++;
                    j++;
                }else{
                    j++;     //如果不相同的话，那么s的下一个元素顶上
                }
                if(i==str.length()){ //因为i只有在两个元素相同时才加，
                                 //所以当i等于字符串的长度时，说明已经找到
               //这一段代码是要写“返回长度最长且字典顺序最小的字符串” 这句话的
                    if(str.length()>target.length()){
                        target=str;
                    }else if(str.length()==target.length()){
                        if(str.compareTo(target)>0)
                            target=str;
                    } else{
                        target=null;
                    }  
                }
           } 
        }
        return target;
    }
}