```
class Solution {
    public String[] findWords(String[] words) {
        List<String> str = new ArrayList();
        if(words.length==0){
            String[] strings = new String[str.size()];
            str.toArray(strings);
            return strings;
        }
        String str1 = "qwertyuiop";
        List<Character> l1 = arrayTolist(str1.toCharArray());
        String str2 = "asdfghjkl";
        List<Character> l2 = arrayTolist(str2.toCharArray());
        String str3 = "zxcvbnm";
        List<Character> l3 = arrayTolist(str3.toCharArray());
        for(int i=0;i<words.length;i++){
            List<Character> temp = arrayTolist(words[i].toLowerCase().toCharArray());
            if(l1.containsAll(temp)||l2.containsAll(temp)||l3.containsAll(temp))//判断该字符串是否在这三行中的任意一个
                str.add(words[i]);
        }
        String[] strings = new String[str.size()];//将List转化为数组返回
        str.toArray(strings);
        return strings;
    }
    public List<Character> arrayTolist(char[] arr) {//将字符数组转化为char列表
    	List<Character> list = new ArrayList();
    	for(char a : arr)
    		list.add(a);
    	return list;
    }
}
```
