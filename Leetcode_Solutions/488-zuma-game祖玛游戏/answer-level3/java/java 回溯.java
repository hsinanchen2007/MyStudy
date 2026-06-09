为什么没有java的，好过分哦，不过这个题的确是有点难。看了一下大神的思路，然后多写了一点注释。
这道题坑太多了
1.本题中dfs其实有两个，第一个是将每个球向指定位置插入，位置可以是从[0，board.length)
2.在每次dfs之前，我们要先判断一下当前字符串中是否有大于等于3个的字符，因为比如：BRRWWRBB，我向WW中放入一个W，之后dfs传入的字符串就变成了了BRRRBB，这其中就包含了RRR，所以需要一个函数去除掉当前字符串中已经大于等于三个的字符（这里涉及一个递归的思想，我去掉RRR之后，就变成了BBB，还需要继续递归，直到找不到相同的，返回这个字符串）
3.为什么findMinStep中判断的结果是
```java
return results==maxBall?-1:results;
```
我们以"WRRBBW", "RB" 这个为例，如果到了怎么都移除不了的时候,在hands为空的时候或hands中不够的那一次dfs时，会返回maxBall的个数，之后返回上一层dfs时，dfs(i-1)在比较的时候，rs=min（maxBall，maxBall(dfs(i))+needBalls），这里又会返回maxBall，所以直到返回第一层dfs时，都会是rs=min（maxBall，maxBall(dfs(1))+needBalls）,最终返回maxBall。所以如果没有办法清除，最终第一层dfs会返回maxBall。
4.dfs的时候，board加上#号的好处，我们不需要考虑走到board中最后一位这种情况。我们让j始终往后跑，去判断是否可以和i的值相等，最后有两种情况：1.字符串为B#，2.字符串为BB#，第一种是j已经走到#号了，i为B，最后i=j，走到#号。第二种情况是j和i都在第一个B处，之后j先走到#，之后i=j时，i和j走到#号。
5.回溯就不用说了，我们在插入该位置去掉手中的这些球，在dfs之后，我们在加回来，因为下一次插球（插入其他位置）可能会用到
```java
class Solution {
    //对board中每一个位置去添加手中的球（前提是添加进去可以消除）之后继续递归，直到手中的球全没有了
    //去判断是否board为空了
    
    //最大为5个
    int maxBall = 6;
    public int findMinStep(String board, String hand) {
        //用整形数组来存储我们手中球
        int[]hands = new int[26];
        for(int i=0;i<hand.length();i++)
            hands[hand.charAt(i)-'A']++;
        //防止出现问题，这个#号加的太精髓了。
        int results = dfs(board+"#",hands);
        return results==maxBall?-1:results;
    }
    //如果怎么都移除不了,在hands为空的时候或hands中不够的那一次dfs时，会返回maxBall的个数
    //之后返回上一层dfs时，dfs(i-1)在比较的时候，min（maxBall，maxBall(dfs(i))+needBalls），
    //这里又会返回maxBall
    //所以直到返回第一层dfs时，都会是min（maxBall，maxBall(dfs(1))+needBalls）,最终返回maxBall
    public int dfs(String board,int []hands)
    {
             
        board = removeConsecutive(board);
        //全移除了
        if(board.equals("#"))
            return 0;
        int rs = maxBall;
        //插入board字符串中的哪一个字符都是可以的哦
        //(走到最后的时候，可能是i指向最后一个字母，而j指向了#，然后进行最后一次判断（尝试为最后一个字母填进去2个球），之后i和j一同走向#。
        //或者是i和j都指向了最后一个#（之前j不是#，j在本次走到#），然后下一次就会停止循环。
        //i永远不会到"#"，或者说即使到了下一次j++就出来了
        //所以不用担心nowBall不是数组中的index。
        for(int i=0,j=0;j<board.length();j++)
        {
            //看看有几个相同的，必然小于三个
            if(board.charAt(i)==board.charAt(j)) continue;
           int needBalls = 3-(j-i);
            int nowBall = board.charAt(i)-'A';
            if(hands[nowBall]>=needBalls)
            {
                //铁憨憨你在外面拼，那不是下一个i的时候也用你这个board了么
                //拼一下（不包含i，包含j）
                //board = board.substring(0,i)+board.substring(j);
                hands[nowBall]-=needBalls;
                //这里不是+1，是加上需要的球
                rs = Math.min(rs,dfs(board.substring(0,i)+board.substring(j),hands)+needBalls);
                //回溯回去
                hands[nowBall]+=needBalls; 
            }
            //这些相同的是一样的，可以直接往后走即可
            i=j;
        }
        return rs;
    }
     /**
    有可能我们将三个球清理之后，又前面后面的碰到一起又超过了三个球
    **/
    private String removeConsecutive(String board) {
        //最后还是会走到j到#，然后i不是#，然后下一次退出。
    for (int i = 0, j = 0; j < board.length(); j++) {
        if (board.charAt(j) == board.charAt(i)) continue;
        if (j - i >= 3) return removeConsecutive(board.substring(0, i) + board.substring(j));
        //继续往后看
        else i = j;
    }
    return board;
    }
}
```
