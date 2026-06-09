```
public class Solution {
    public bool IsOneBitCharacter(int[] bits) {
        int i = 0;//初始化下标为0
        //思路：当是2比特时，下标就加2；是1比特时，下标就加1.
        //最后得到的下标是否和bits的最后一个值的下标相等，如果相等，说明返回时1比特，否则是2比特   
        while(i < bits.Length-1){
            i = bits[i] == 1 ? i+2 : i+1;
        }
        if(i == bits.Length-1){
            return true;
        }else{
            return false;
        }
       
        
    }
}
```