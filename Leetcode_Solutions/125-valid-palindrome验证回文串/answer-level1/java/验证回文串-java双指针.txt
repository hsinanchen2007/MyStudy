```
class Solution {
    public boolean isPalindrome(String s) {
        /*
        只考虑数字和字母    
        static boolean	isDigit(char ch)   
        static boolean	isLetter(char ch)
        static boolean	isLetterOrDigit(char ch)
        忽略字母大小写
        s.toLowerCase(); 
        */
        if(s==null||s.length()<=0){
            return true;
        }
        
        s=s.toLowerCase();
        //使用双指针
        int begin=0;
        int end=s.length()-1;
        while(begin<end){
            char ch1=s.charAt(begin);
            char ch2=s.charAt(end);
            
            //使用if 只判断了一次非法字符  如果非法字符连续出现
            //使用while循环 也要注意字符串只有连续的非法字符  容易导致越界   
            // 可以使用continue  让它进入下一次循环来实现 也可以使用循环嵌套来实现
            if(!Character.isLetterOrDigit(ch1)){
                begin++;
                continue;
            }
            if(!Character.isLetterOrDigit(ch2)){
                end--;
                continue;
            }
        
            
            if(ch1==ch2){
                begin++;
                end--;
            }else{
                return false;
            }
        }
        return true;
    }
}
```
