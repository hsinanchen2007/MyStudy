### 解题思路
我的方法倒在了倒数第二个测试案例上面。
10000000000，超过了内存限制。然后看了一下题解，发现是一道数学题......

### 代码

```java
class Solution {
    // public int lastRemaining(int n) {
        // if(n < 1)
        //     return 0;
        // int[] array = new int[n];
        // int len = n;
        // for(int i = 0; i < n; i++){
        //     array[i] = i + 1;
        // }
        // int flag = 1;
        // while(len != 1){
        //     if(flag == 1){
        //         for(int i = 0; i < len;){
        //             array[i] = 0;
        //             i += 2;
        //         }
        //         flag *= -1;
        //     }
        //     else{
        //         for(int i = len - 1; i >= 0;){
        //             array[i] = 0;
        //             i -= 2;
        //         }
        //         flag *= -1;
        //     }

        //     int[] array1 = new int[len/2];
        //     for(int i = 0, j = 0; i < len;){
        //         if(array[i] != 0){
        //             array1[j] = array[i];
        //             j += 1;
        //         }
        //         i++;
        //     }
        //     array = array1;
        //     len /= 2;
        // }
        // return array[0];
    // }

    public int lastRemaining(int n) {
        return help(n);
    }
    
        public static int help(int n){
    	if(n==2)
            return 2;
    	if(n==1)
            return 1;
    	if(n%2==1){
    		return help(n-1);
    	}else{
    		return 2*(n/2+1-help(n/2));
    	}
    }
}
```