/**
 * Project:
 * Author : zhaozhen
 * Email  :
 * Date   : 2019/10/9
 *
 * 解题思路: 1.hash存储 暴力遍历的方法 使用String.compareTo()进行比较   2.使用Array.sort()进行预排序(字典序) 然后进行线性扫描
 * 
 * 注意: Array.sort() 的使用
 *
 */
```
public String longestWord(String[] words) {
    HashMap<String,Integer> hashMap = new HashMap<>();
    for(int i = 0;i < words.length;i++){
        hashMap.put(words[i],0);
    }

    String res = "";

    for(int i = 0;i < words.length;i++){
        boolean is_ok = true;
        for(int j = 0;j < words[i].length();j++){
            String t = words[i].substring(0,j+1);
            if(!hashMap.containsKey(t)){
                is_ok = false;
                break;
            }
        }
        if(is_ok){
            if(res.length() < words[i].length()){
                res = words[i];
            }else if(res.length() == words[i].length() && res.compareTo(words[i]) > 0){
                res = words[i];
            }
        }
    }

    return res;
}

public String longestWord2(String[] words){
    String res=  "";
    //字典排序
    Arrays.sort(words);
    HashSet<String> hashSet = new HashSet<>();
    for(String s:words){
        if(s.length() == 1 || hashSet.contains(s.substring(0,s.length()-1))){
            res = s.length() > res.length()?s:res;
            hashSet.add(s);
        }
    }
    return res;
}








//升序排列 (小的在前)
Arrays.sort(a,new Comparator<Integer>(){
    public int compare(Integer o1, Integer o2) {
        return o1 - o2;
    }
});

int debug = 0;

//降序排列
Arrays.sort(a, new Comparator<Integer>() {
    public int compare(Integer o1, Integer o2) {
        return o2 - o1;
    }
});

debug=0;

//字典序顺序 (小的在前)
Arrays.sort(s, new Comparator<String>() {
    public int compare(String o1, String o2) {
        return o1.compareTo(o2);
    }
});
debug = 0;
//字典序降序
Arrays.sort(s, new Comparator<String>() {
    public int compare(String o1, String o2) {
        return o2.compareTo(o1);
    }
});
debug = 0;

//字符串长度排序 升序 (小的在前)
Arrays.sort(s, new Comparator<String>() {
    public int compare(String o1, String o2) {
        return o1.length() - o2.length();
    }
});
debug = 0;

//字符串长度排序 降序 
Arrays.sort(s, new Comparator<String>() {
    public int compare(String o1, String o2) {
        return o2.length() - o1.length();
    }
});
```