class Solution {
    public boolean isSubsequence(String s, String t) {
       int index = 0,indexS=0,count = 0;   //index为t的索引，indexS为s的索引，count用于统计s是否在t里面，是则加1

              
        while(index<t.length()){        
            if(indexS>=s.length()) break;   //如果indexS大于s的长度，则表示，全找到了。
            char temp = s.charAt(indexS);   //获取s当前的字符
            if(temp==t.charAt(index)){      //如果与t当前的字符相等
                count++;                    //count值加1
                index++;                    //t与s均到下一个字符
                indexS++;
                continue;
            }else{
                index++;                    //当前t的字符与s的当前字符不等，则与t的下一个字符比较
            }
        }
        

        if(count==s.length()){              //count值与s的长度相等则表示是子序列，否则返回false
            return true;
        }else return false;
    }
}