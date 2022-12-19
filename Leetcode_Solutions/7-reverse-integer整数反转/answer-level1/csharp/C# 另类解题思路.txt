直接亮代码
```
public class Solution {
    public int Reverse(int x) {
        try{
            int result=0;
            checked{
                while(x!=0){
                    result= result*10+x%10;
                    x=x/10;
                }
            }
            return result;
        }
        catch{
            return 0;
        }
    }
}
```
利用取模和除法运算反转，再利用内置checked语法检测是否有内存溢出，若有，则返回0。
