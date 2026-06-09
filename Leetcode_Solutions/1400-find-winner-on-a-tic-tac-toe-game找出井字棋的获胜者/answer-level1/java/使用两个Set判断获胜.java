### 解题思路
井字棋获胜的情况是可以穷举的，将胜利的结果存到set中，井字棋一共有九个位置，设置成
1，2，3
4，5，6
7，8，9
直接判断两个set是否存在获胜

### 代码

```java
class Solution {
    public String tictactoe(int[][] moves) {
        Set<Integer> a = new HashSet<>();
        Set<Integer> b = new HashSet<>();
        for(int i=0;i<moves.length;i++){
            if(i%2==0){
                a.add(moves[i][0]*3+moves[i][1]+1);
            }else{
                b.add(moves[i][0]*3+moves[i][1]+1);
            }
        }
        if(isWinPerson(a)){
            return "A";
        }else if(isWinPerson(b)){
            return "B";
        }else if(moves.length == 9){
            return "Draw";
        }else{
            return "Pending";
        }

    }
    private boolean isWinPerson(Set<Integer> set){
        if((set.contains(1)&&set.contains(2)&&set.contains(3))||
            (set.contains(4)&&set.contains(5)&&set.contains(6))||
            (set.contains(7)&&set.contains(8)&&set.contains(9))||
            (set.contains(1)&&set.contains(4)&&set.contains(7))||
            (set.contains(2)&&set.contains(5)&&set.contains(8))||
            (set.contains(3)&&set.contains(6)&&set.contains(9))||
            (set.contains(1)&&set.contains(5)&&set.contains(9))||
            (set.contains(3)&&set.contains(5)&&set.contains(7))){
            return true;
        }else{
            return false;
        }
    }
}
```