![image.png](https://pic.leetcode-cn.com/47a926207ddffc72182dc43eff0d6f27abd211556a841fb18605460f222d1b4c-image.png)
```
//如果结束的时候朝北:需要停在原地，否则沿着这条路一直走下去
//如果结束的时候朝西或东:机器人会沿着一个正方形走回
//如果结束的时候朝南:机器人会原路返回
class Solution {
    public boolean isRobotBounded(String instructions) {
        //direction: 0:N 1:W 2:S 3:E
        int direction, i;
        int[] counts;
        
        direction = 0;
        counts = new int[4];
        for(i = 0; i < instructions.length(); i++)
            if(instructions.charAt(i) == 'G')
                counts[direction]++;
            else if(instructions.charAt(i) == 'L'){
                if(direction == 3)
                    direction = 0;
                else
                    direction++;
            }else{
                if(direction == 0)
                    direction = 3;
                else
                    direction--;
            }
        if(direction == 0)
            return counts[0] == counts[2] && counts[1] == counts[3];
        return true;
    }
}
```
