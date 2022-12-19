```
131. public class Partition131 {
    public static void main(String[] args) {
        new Partition131().partition("aad");
    }
    List<List<String>> lists = new ArrayList<>();
    public List<List<String>> partition(String s) {
        if(s == null || s.length() == 0){
            return lists;
        }
        List<String> list = new ArrayList<>();
        process(s,list,0);
        return lists;
    }

    private void process(String s, List<String> list, int index){
        if(index == s.length()){
            lists.add(new ArrayList<>(list));
            return;
        }
        for (int i = index+1; i <=s.length() ; i++) {
            String str = s.substring(index,i);
            if(isParlindrome(str)){
                list.add(str);
                process(s,list,i);
                //list相当于引用传递，所以需要回退
                list.remove(list.size()-1);
            }
        }
    }
    private boolean isParlindrome(String s){   //判断是否为回文串
        if(s==""||s.length()==0){
            return false;
        }
        int len=s.length();
        for(int i=0;i<=len/2;++i){
            if(s.charAt(i)!=s.charAt(len-1-i)){
                return false;
            }
        }
        return true;
    }

}

```
