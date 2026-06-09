（1）、时间复杂度，空间复杂度都很高，虽然a了，但是排名垫底
使用迭代的方法，字符串每增加一个字符都是在原来的字符串的回文串的结果上进行添加的，添加的方式有两种：
（a）、原来的每个结果列表添加一个 单独的新的字符替换原来的列表。
（b）、原来的结果的列表从后开始遍历，如果某个字符串的开头和新的字符相等，那么从这个字符串开始一直到列表的末尾，以及新的字符，组成的字符串就有可能是一个新的回文串，那么
判断一下，如果是的话，那么这个回文串，再加上列表里字符串之前的字符串组成的新的列表就是一个新的结果。
```
class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> res = new ArrayList<>();
        List<String> l = new ArrayList<>();
        res.add(l);
        int len = s.length();
        if (len == 0) return res;
        int i = 0;
        while(i < len){
            int size = res.size();
            for(int j = 0; j < size; j++){
                List<String> tmp_l = res.get(j);
                for(int k = tmp_l.size() - 1; k >= 0; k--){
                    if(tmp_l.get(k).charAt(0) == s.charAt(i)){
                        String tmp_s = huiwen(tmp_l, k, s.charAt(i));
                        if(tmp_s.length() > 0){
                            List<String> new_l = new ArrayList<>(tmp_l.subList(0,k));
                            new_l.add(tmp_s);
                            if(!res.contains(new_l))
                                res.add(new_l);
                        }
                    }
                }
                tmp_l.add(String.valueOf(s.charAt(i)));
            }
            i++;
        }
        return res;
    }
    public String huiwen(List<String> l, int start, char c){
        String res = "";
        for(int i = start; i < l.size(); i++){
            res += l.get(i);
        }
        res += String.valueOf(c);
        int i = 0, j = res.length() - 1;
        while(i < j){
            if(res.charAt(i) != res.charAt(j))
                return "";
            i++;
            j--;
        }
        return res;
    }
}
```