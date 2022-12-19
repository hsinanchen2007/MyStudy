![image.png](https://pic.leetcode-cn.com/311a591123d991c1ececb2ddc35f6b11627a9dc90c778540d91557aafb12f7fe-image.png)
son代表这个数字后面可以跟几个10** ****
当遇到一个有son的数字时，要检查前面的son是不是已经耗尽，如果没有耗尽直接返回false。比如 235后面应该有2个son，但是他的下一个数字是200，这不满足规则，在235的son变为0之前是不允许出现的带有son的数字的(以及0~128的情况)。
同时，如果son不够用了，比如235后面只能跟2个10\** **\**, 这时候出现了第三个10\** ****,则也要返回false
````
class Solution {
    public boolean validUtf8(int[] data) {
        if(data == null)
            return false;
        int son = 0;
        for(int i = 0 ; i < data.length;i++){
            if(data[i] >= 0 && data[i] < 128 && son == 0)
                son = 0;
            else if(data[i]>=128 && data[i] <192)
                son--;
            else if(data[i]>=192 && data[i]<224 && son == 0){
                son = 1;
            }
            else if(data[i]>=224 && data[i]<240 && son == 0)
                son = 2;
            else if(data[i]>=240 && data[i]<248 && son ==0)
                son = 3;
            else 
                return false;
            
            if(son<0)
                return false;
        }
        return son==0;
    }
}

````