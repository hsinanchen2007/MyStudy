### 解题思路
使用字符数组来表示中心对称数字num。
使用递归函数helper从首位到中间位置依次安排中心对称的数字，每安排一个数字在一个位置，与它对称的位置会存放这个数字的中心对称数字，这样安排到中间位置后中心对称的num就找到了。需要注意两点：如果n是奇数，中间位置只能存放0,1,8;数字的开头不能为0，n==1时除外。
中心对称数字（0，1，8，6，9）使用字符数组opt来保存，optSymmetry保存opt中元素的中心对称数字（0，1，8，9，6）。
### 代码

```java
import java.util.*;
class Solution {
    char[] opt=new char[]{'0','1','8','6','9'};
    char[] optSymmetry=new char[]{'0','1','8','9','6'};
    int n;
    List<String> ans=new ArrayList<String>();
    public List<String> findStrobogrammatic(int n) {
        this.n=n;
        char[]  num=new char[n];
        helper(0,num);
        return ans;
    }
    void helper(int i,char[] num){
        if(i==n/2){
            if(n%2!=0){
                for(int j=0;j<3;j++){
                    num[i]=opt[j];
                    ans.add(String.valueOf(num));
                   
                }
            }
            else
                ans.add(String.valueOf(num));
            return;
        }
        for(int j=i==0?1:0;j<opt.length;j++){
            num[i]=opt[j];
            num[n-1-i]=optSymmetry[j];
            helper(i+1,num);
            
        }
        return;
    }
    
}
```