![image.png](https://pic.leetcode-cn.com/42e8b396923f91a66643235e53706f20b161d4fccdd6952b218c551ab5d689f5-image.png)

利用一个int数组记录给定的数组中0-9所有数字出现的次数
求所有数字总和并且计算出除以3的余数。
遍历创建的int数组，从1开始，记录每次减少当前数字i乘以个数j后余数可以整除时候的被移除数i和所移除次数j
要注意被移除次数小的优先
如 1,1,1,2的结果应该是 111 而不是 21 
false的条件是总和余数不为0且i*j==0
最后把移除数字以后的数组从9开始按照数量挨个添加到字符串中返回即可

```
class Solution {
    public String largestMultipleOfThree(int[] digits) {
        
        int[] map = new int [10];
        Arrays.fill(map,0);
        for(int i=0;i<digits.length;i++){
            map[digits[i]]++;
        }
        
        int t = 0;
        for(int i=0;i<10;i++){
            t += map[i]*i;
        }
        if(t==0) return"0";

        int yu = t%3;
        int minus = 0;
        int index = 1000;

        int flag = 0; 
        for(int i=1;i<10;i++){      
            for(int j = 0;j<=map[i];j++){
                if((yu -i*j)%3 == 0){       

                    if(j<index){
                        minus = i;
                        index = j;
                    }
                    break;
                }
            }
        }
 
        if(yu!=0 && (minus*index)==0) return "";
        map[minus]-=index;
        
        StringBuffer sb =new StringBuffer();
        for(int i=9;i>=0;i--){
            for(int j=0;j<map[i];j++){
                sb.append(String.valueOf(i));
            }
        }
        return sb.toString();
        
        
    }
    
  
}
```
