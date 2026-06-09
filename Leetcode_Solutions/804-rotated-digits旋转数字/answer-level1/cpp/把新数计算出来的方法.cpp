看了下评论，好多人用的是不用把新数计算出来的方法。即原数的某位如果转换后是无效数，则直接跳过该数不计入统计；当且仅当原数全位数都存在有效变化，且至少一位数的有效变换不同于原数时才计入统计。这种方法不需要把新数计算出来，节省了计算量。

我写的还是把新数给计算了出来，效率也还算可以。



执行用时 :4 ms, 在所有 C++ 提交中击败了91.24%的用户内存消耗 :8.1 MB, 在所有 C++ 提交中击败了92.97%的用户

```
class Solution {
public:
    bool judge(int num){//好数判断函数
        
        int new_num = 0;//原数逐个旋转180度后的新数
        
        int n = 1;//倍数
        
        int temp1 = num;//原数副本
        
        while(temp1>0){
            
            int temp2;//原数每位数的副本
            
            if(temp1 >= 10)
                temp2 = temp1%10;
            else
                temp2 = temp1;
            
            switch(temp2)//根据规则转换原数的每位数
            {
                    case(0):
                    case(1):
                    case(8):
                    break;
                    
                    case(2):temp2 = 5;
                    break;
                    
                    case(5):temp2 = 2;
                    break;
                    
                    case(6):temp2 = 9;
                    break;
                    
                    case(9):temp2 = 6;
                    break;
                    
                    case(3):
                    case(4):
                    case(7):
                    return false;
                    break;
            }
            
            new_num += temp2 * n;
            n *= 10;
            
            temp1 = temp1/10;
        }
             
        if(new_num != num)
            return true;
        
        return false;
    }
    
    int rotatedDigits(int N) {
        
        int count = 0;//好数统计
        
        for(int i=0; i<=N; i++){
  
            if(judge(i) == true){
                count++;
            }
            
        }
        
        return count;
    }
};
```
