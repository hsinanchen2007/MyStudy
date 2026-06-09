两次遍历字符串，第一次找出猜对的，第二次找出伪猜对的。```
代码块
class Solution {
    public int[] masterMind(String solution, String guess) {
        StringBuilder s=new StringBuilder(solution);
        StringBuilder g=new StringBuilder(guess);
        int[] out=new int[2];
        int i=0;
        while(i<s.length()){
            if(s.charAt(i)==g.charAt(i)){
                out[0]++;
                s.deleteCharAt(i);
                g.deleteCharAt(i);
            }
            else{i++;}
        }
        for(int j=0;j<g.length();j++){
            int in=s.indexOf(Character.toString(g.charAt(j)));
            if(in!=-1){
                out[1]++;
                s.deleteCharAt(in);
            }
        }
        return out;
    }
}
```
代码块
```
