```
class Solution {
    public int mySqrt(int x) {
        
        if (x == 0 || x == 1) {
            return x;
        }
        
        int left = 1;
        int right = x;
        int res = 0;

        while (left <= right) {
            int middle = (left + right) / 2;
            if (middle == x / middle){ 
            //    System.out.println(middle);
                return middle;
            }
            
            if ( middle > x / middle) {
                right = middle - 1;  
            } else {  
                left = middle + 1;   
                // 如果没有直接结果，最后一个乘积小于x的就是结果
                res = middle;
            }
        }
        return res; 
    }
}
```
