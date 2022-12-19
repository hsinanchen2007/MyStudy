一次编辑，意味着只有0次或1次出错的机会，根据这个思路分情况求解。
```
 public static boolean oneEditAway(String first, String second) {
        if(first.equals(second)) return true;
        int errorNums=0;
        if(first.length()==second.length()){
            //字符长度一致的情况下，仅可能是替换着一种情况
            for(int i=0;i<first.length();i++){
                if(first.charAt(i)!=second.charAt(i)){
                    errorNums++;
                    if(errorNums>1)return false;
                }
            }
            return true;
        }else if(first.length()-1==second.length() || second.length()-1==first.length()){
            //不然就是增加或删除，这两者是一回事。先知道谁大谁小，遍历小的那一个
            String longString=first.length()>=second.length()?first:second;
            String shortString=first.length()>=second.length()?second:first;
            for(int i=0;i<shortString.length();i++){
                //由于只有一次出错机会，长的字符串的比较位置是i+errorNums，这一步是关键（出错位置在中间）
                if(longString.charAt(i+errorNums)!=shortString.charAt(i)){
                    errorNums++;
                    if(errorNums>1)return false;
                    i--;
                }
            }
        }else{
            return false;
        }
        return true;
       
    }
```
