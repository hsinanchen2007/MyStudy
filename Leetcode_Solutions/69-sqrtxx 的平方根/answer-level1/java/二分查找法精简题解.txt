
```java []
class Solution {
    public int mySqrt(int x) {
        //排除特殊情况
        if(x == 1) return 1;
        if(x <1) return 0;
        //46340 * 46340 = 2147395600 
        if(x > 2147395600) return 46340;
      
        int left =1;
        //int 类型最大的数的平方根为46340
        int right = 46340;
        int result=-1;
        while(left<=right){
            //二进制左移运算相当于*2
            int mid = (left+right+1) >> 1;
            int nextNum = mid+1;
            // x的值可能介于两个相邻的数的平方之间
            double midSquare = mid*mid;
            double nextNumSquare = nextNum*nextNum;
            if(midSquare == x ){
                result = mid;
                break;
            }else if(nextNumSquare == x){
                result = mid+1;
                break;
            }else if(midSquare< x && nextNumSquare>x){
                result = mid;
                break;                
            }else if(midSquare<x && nextNumSquare<x){
                left = mid+1;
            }else{
                right = mid-1;   
            }
        }
        return result;
    }
}
```

