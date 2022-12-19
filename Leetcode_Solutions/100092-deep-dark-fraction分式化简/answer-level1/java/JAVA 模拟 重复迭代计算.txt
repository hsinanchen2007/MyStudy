**用两个变量分别记录分子和分母，由于1/的缘故，所以每次读取元素时需要交换m和n的位置。
迭代计算，仅需要对数组元素进行倒序读取即可。
用一个子函数化简**

![1.png](https://pic.leetcode-cn.com/079e0abc3f742bfa22e8e8377377a041e2cc5c797ff572296474bf29d07971ee-1.png)

```
class Solution {
    public static int test1(int a,int b){
        int max=a>b?a:b;
        int min=a<b?a:b;
        int c =max%min;
        if(c==0){
            return min;
        }
        return test1(c,min);
    }
    public int[] fraction(int[] cont) {
        int[] ans = new int [2];
        ans[0] = cont[cont.length-1];
        ans[1] = 1;
        if(cont.length==1) return ans;
        else{
            int n=cont[cont.length-1],m=1;
            int temp;
            for(int i=cont.length-2;i>=0;i--){ 
                temp = n;
                n = m;
                m = temp;
                if(cont[i] == 0||n == 0)
                    continue;
                if(m == 1){
                    n += cont[i];
                }
                else{
                    n = cont[i]*m + n;
                }
            }
            int gy = test1(n,m);
            if(gy == 0) gy = 1;
            ans[0] = n/gy;
            ans[1] = m/gy;
            return ans;
        }
    }
}
```
