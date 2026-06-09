

1. 数学公式

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        Stack<int[]> stack  = new Stack<>();
        // 序列里整数数量
        int n = 2;
        while(true){
            if((2* target + n - n*n) < n*2 ) break;
        
            if((2 * target + n - n*n) % (2*n) == 0){
                int startIndex = (target*2 + n - n*n)/(2*n) ;
                int[] num =new int[n];
                for(int i = 0;i<n;i++){
                    num[i] = startIndex+i;
                }
                stack.push(num);
            }
            n++;
        }

        int size = stack.size();
        int[][] result = new int[size][size];
        for(int i =0 ;i<size;i++){
            result[i] = stack.pop();
        }

        return result;
    }


}

```





2. 滑动窗口
```java

class Solution {
    public int[][] findContinuousSequence(int target) {
        List<int[]> v = new ArrayList<>();
        int i = 1,j = 2;
        while(i <= target/2 ){
            int sum = getSum(i,j);
            if(sum < target){
                j++;
            }else if(sum == target){
                int[] num = new int[j-i+1];
                for(int a = 0;a< j-i+1 ; a++){
                    num[a] = i+a;
                }
                v.add(num);
                i++;j++;
            }else{
                i++;
                j =  i+1;
            }
        }


        int size = v.size();
        int[][] result = new int[size][size];
        for(int im =0 ;im<size;im++){
            result[im] = v.get(im);
        }


        return result;

    }


    private int getSum(int i,int j){
        int n = j-i+1;
        return n*i + (n * (n-1))/2 ;
    }
}

```
