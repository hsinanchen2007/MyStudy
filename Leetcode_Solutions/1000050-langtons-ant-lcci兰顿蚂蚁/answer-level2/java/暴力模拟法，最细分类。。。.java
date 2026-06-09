### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    private List<List<Character>> list=new ArrayList<>();
    public List<String> printKMoves(int K) {
        List<Character> mid= new ArrayList<>();
        mid.add('_');
        if (K==0) {
            List<String> res=new ArrayList<>();
            res.add("R");
            return res;
        }
        list.add(mid);
        helper(0,0,K,'R');

        List<String> res=new ArrayList<>();
        for (List<Character>i:list){
            StringBuilder sb=new StringBuilder();
            for (char j:i){
                sb.append(j);
            }
            res.add(sb.toString());
        }
        return res;
    }

    private void helper(int x,int y,int times,char dir){
        if (times==0) {
            List<Character> mid=list.get(x);
            mid.set(y,dir);
            list.set(x,mid);
            return;
        }

        char next;
        int nextX=x,nextY=y;
        if (dir=='R'){//头冲右
            if (list.get(x).get(y)=='_') {
                next = 'D';

                List<Character> mid=list.get(x);//把要离开的格翻转
                if (mid.get(y)=='_')
                    mid.set(y,'X');
                else
                    mid.set(y,'_');
                list.set(x,mid);

                nextX=x+1;
                if (x==list.size()-1){
                    List<Character> more=new ArrayList<>();
                    for (int i=0;i<list.get(0).size();i++)
                        more.add('_');
                    list.add(more);
                }
            }
            else {
                next = 'U';

                List<Character> mid=list.get(x);//把要离开的格翻转
                if (mid.get(y)=='_')
                    mid.set(y,'X');
                else
                    mid.set(y,'_');
                list.set(x,mid);

                nextX=Math.max(0,x-1);
                if (x==0){
                    List<Character> more=new ArrayList<>();
                    for (int i=0;i<list.get(0).size();i++)
                        more.add('_');
                    list.add(0,more);
                }
            }
        }
        else if (dir=='L'){//头冲左
            if (list.get(x).get(y)=='_') {
                next = 'U';

                List<Character> mid=list.get(x);//把要离开的格翻转
                if (mid.get(y)=='_')
                    mid.set(y,'X');
                else
                    mid.set(y,'_');
                list.set(x,mid);

                nextX=Math.max(0,x-1);
                if (x==0){
                    List<Character> more=new ArrayList<>();
                    for (int i=0;i<list.get(0).size();i++)
                        more.add('_');
                    list.add(0,more);
                }
            }
            else {
                next = 'D';

                List<Character> mid=list.get(x);//把要离开的格翻转
                if (mid.get(y)=='_')
                    mid.set(y,'X');
                else
                    mid.set(y,'_');
                list.set(x,mid);

                nextX=x+1;
                if (x==list.size()-1){
                    List<Character> more=new ArrayList<>();
                    for (int i=0;i<list.get(0).size();i++)
                        more.add('_');
                    list.add(more);
                }
            }
        }
        else if (dir=='U'){//头冲上
            if (list.get(x).get(y)=='_') {
                next = 'R';

                List<Character> mid=list.get(x);//把要离开的格翻转
                if (mid.get(y)=='_')
                    mid.set(y,'X');
                else
                    mid.set(y,'_');
                list.set(x,mid);

                nextY=y+1;
                if (y==list.get(0).size()-1){
                    for (int i=0;i<list.size();i++) {
                        List<Character> more = list.get(i);
                        more.add('_');
                        list.set(i,more);
                    }
                }
            }
            else {
                next = 'L';

                List<Character> mid=list.get(x);//把要离开的格翻转
                if (mid.get(y)=='_')
                    mid.set(y,'X');
                else
                    mid.set(y,'_');
                list.set(x,mid);

                nextY=Math.max(0,y-1);
                if (y==0){
                    for (int i=0;i<list.size();i++) {
                        List<Character> more = list.get(i);
                        more.add(0,'_');
                        list.set(i,more);
                    }
                }
            }
        }
        else {//头冲下
            if (list.get(x).get(y)=='_') {
                next = 'L';

                List<Character> mid=list.get(x);//把要离开的格翻转
                if (mid.get(y)=='_')
                    mid.set(y,'X');
                else
                    mid.set(y,'_');
                list.set(x,mid);

                nextY=Math.max(y-1,0);
                if (y==0){
                    for (int i=0;i<list.size();i++) {
                        List<Character> more = list.get(i);
                        more.add(0,'_');
                        list.set(i,more);
                    }
                }
            }
            else {
                next = 'R';

                List<Character> mid=list.get(x);//把要离开的格翻转
                if (mid.get(y)=='_')
                    mid.set(y,'X');
                else
                    mid.set(y,'_');
                list.set(x,mid);

                nextY=y+1;
                if (y==list.get(0).size()-1){
                    for (int i=0;i<list.size();i++) {
                        List<Character> more = list.get(i);
                        more.add('_');
                        list.set(i,more);
                    }
                }
            }
        }
        helper(nextX,nextY,times-1,next);
    }
}
```