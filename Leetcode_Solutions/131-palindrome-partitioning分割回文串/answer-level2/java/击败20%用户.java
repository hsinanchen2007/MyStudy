### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    private List<List<String>> ret = new ArrayList<>(); 
    public List<List<String>> partition(String s) {
        if(s.length() == 0){
            return ret;
        }
        List<String> already = new ArrayList<>();
        backtracking(already, s, 0);
        return ret;


    }
    private void backtracking(List<String> already, String s, int start){
        if(start == s.length()){
            ret.add(new ArrayList<>(already));
            return;
        }
        for(int i = start + 1; i <= s.length(); i++){
            String tem = s.substring(start, i);
            if(isValid(tem)){
                already.add(tem);
                backtracking(already, s, i);
                already.remove(already.size() - 1);
            }
        }
        return;
    }
    // 判断一个字符串是否为回文串
    private boolean isValid(String s){
        if(s.length() == 1){
            return true;
        }
        // 两个指针，分别指向字符串首和尾
        int p1 = 0;
        int p2 = s.length() - 1;
        while(p2 > p1){
            if(s.charAt(p1) != s.charAt(p2)){
                return false;
            }
            p2--;
            p1++;
        }
        return true;
    }
}
```