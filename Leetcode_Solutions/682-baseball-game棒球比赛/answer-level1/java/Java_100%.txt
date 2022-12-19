### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {

    public int calPoints(String[] ops) {
        int score=0;
        int[] count=new int[ops.length];
        int cur=-1;
        for(int i=0;i<ops.length;i++){
            int t=0;
            if(ops[i].equals("C")){
                score-=count[cur--];
            } else if(ops[i].equals("D")){
                t=count[cur]<<1;
                score+=t;
                count[++cur]=t;
            } else if(ops[i].equals("+")){
                if(cur>=0){
                    t=count[cur];
                } 
                if(cur>0){
                    t+=count[cur-1];
                }
                score+=t;
                count[++cur]=t;
            } else {
                t=Integer.parseInt(ops[i]);
                count[++cur]=t;
                score+=t;
            }
        }
        return score;
    }

    public int calPoints1(String[] ops) {
        int score=0;
        List<Integer> list=new ArrayList<>();
        for(int i=0;i<ops.length;i++){
            if(ops[i].equals("C")){
                score-=list.get(list.size()-1);
                list.remove(list.size()-1);
            } else if(ops[i].equals("D")){
                int t=list.get(list.size()-1)<<1;
                score+=t;
                list.add(t);
            } else if(ops[i].equals("+")){
                int count=2;
                int t=0;
                if(list.size()>0){
                    t+=list.get(list.size()-1);
                }
                if(list.size()>1){
                    t+=list.get(list.size()-2);
                }
                score+=t;
                list.add(t);
            } else {
                list.add(Integer.parseInt(ops[i]));
                score+=Integer.parseInt(ops[i]);
            }
        }
        return score;
    }
}
```