该结构有一个特点：  
  
1. 0和其之前的所有1一定可以组合成功，但是0不一定是单独进行匹配可能和1组成10  
2. 因为0不可以作为开头(即：‘01’，而‘00’则可以看做两个单独的0)0可以作为分割位  
  
由上面两个特点，只需要判断最后一位0至前一个0之间的比特位(0...0]是否是偶数个1即可  

```
class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        if (bits.length <= 1)
            return true;
        
        // 之后的情况的共同特征是：最后两位是1 0  ;则1必须和前面消去才行,所以这个1需要被前面的1来匹配；直到遇到0即可,即两个0之间相差偶数个1即可  
        int num = 0;
        for (int i = bits.length - 2; i >= 0; i --) {
            int a = bits[i];
            num = a == 1 ? num + 1 : num;
            if (a == 0)
                break;
        }
        return num % 2 == 0;
    }
}
```
