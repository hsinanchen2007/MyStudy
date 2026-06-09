![image.png](https://pic.leetcode-cn.com/c4c1c6674ec1d2ee559a086ff66f6b34cfe7cba9f1486c52ec8ccd0e4d21b7c9-image.png)
```
public int[] sortArrayByParity(int[] A) {
            if (A.length<2)
                return A;
            //原地交换，减少内存占用
            int i=0;//找到奇数索引
            int j=A.length-1;//偶数索引
            while (i<j){
                while (i<A.length && (A[i]&1) == 0)//遇到偶数的时候i++
                    i++;
                while (j>=0 && (A[j]&1)==1) j--;
                if (i<j && i<A.length && j>=0) {
                    int temp = A[i];
                    A[i] = A[j];
                    A[j] = temp;
                    i++;
                    j--;
                }
            }
            return A;
        }
```
