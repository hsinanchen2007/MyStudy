![image.png](https://pic.leetcode-cn.com/a14acb1fa4c1aec449de1e747ca581fd004381d6aea661f6c6ee6e3e893aaf8e-image.png)

```
class Solution {
    public int[] printNumbers(int n) {
        int max=0;
        //判断输出最大数，有几位就为几个9
        while(n>0){
            max=max*10+9;
            n--;
        }
        int[] arr=new int[max];
        for(int i=0;i<max;i++){
            arr[i]=i+1;
        }
        return arr;
    }
}
```
