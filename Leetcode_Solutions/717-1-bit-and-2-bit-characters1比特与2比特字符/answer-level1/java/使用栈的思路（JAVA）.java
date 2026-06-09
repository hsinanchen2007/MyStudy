类似合法括号那一题的思路，利用一个辅助栈来解决该问题，如果当前循环中值为1且栈为空则向栈中填入一个值，如果当前循环中栈是非空的则将值从栈中弹出，到最后一次循环时，判断栈是否空，栈空则是1比特字符，栈不空则是2比特字符。


```
class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        Stack<Integer> helper = new Stack<Integer>();
        for(int i=0;i<bits.length-1;i++){
            if(helper.isEmpty() && bits[i]==1){
                helper.push(1);
            }else if(!helper.isEmpty()){
                helper.pop();
            }
        }
        if (helper.isEmpty()){
            return true;
        }else{
            return false;
        } 
    }
}

```

