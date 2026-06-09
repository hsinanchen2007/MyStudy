```
class Solution {
    public boolean oneEditAway(String first, String second) {
        //小的字符串放在前面，大的放后面
        if(first.length() > second.length()){
            String temp = first;
            first = second;
            second = temp;
        }
        
        if(second.length()-first.length()>1){
            return false;
        }else {
            if(second.length() == first.length()){
                //判断是否可以替换,两处相同位置不同就return false
                int count = 0;
                for (int i = 0; i <first.length() ; i++) {
                    if(first.charAt(i) != second.charAt(i)){
                        count++;
                        if(count == 2){
                            return false;
                        }
                    }
                }
            }else {
                //判断是否通过加就行
                for (int i = 0; i <first.length() ; i++) {
                    if(first.charAt(i)!=second.charAt(i) && first.charAt(i) !=second.charAt(i+1)){
                        return false;
                    }
                }
            }
        }
        return true;
    }
}
```
