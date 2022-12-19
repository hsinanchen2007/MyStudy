### 解题思路
![1X6J196HHG4W@Z2MDXZ8~{S.png](https://pic.leetcode-cn.com/c5db3ac17944f58bebe798dc796227c06fc9731771c01fc8ebaedef7a873d2c5-1X6J196HHG4W@Z2MDXZ8~%7BS.png)


### 代码

```java
class Solution {
    public List<Integer> pancakeSort(int[] A) {
        int l=A.length;
        ArrayList<Integer> B=new ArrayList<>();

        for(int p=0;p<l-1;p++){
            int temp=0;
            for( int i=0;i<l-p;i++){
                if(A[i]>A[temp]){
                    temp=i;
                }
            }
            B.add(temp+1);

            B.add(l-p);

            int tt;
            int m=0;
            int w=temp;
            while(m<w){
                tt=A[w];
                A[w]=A[m];
                A[m]=tt;
                m++;
                w--;
            }
           
             m=0;
             w=l-p-1;
            while(m<w){
                tt=A[w];
                A[w]=A[m];
                A[m]=tt;
                m++;
                w--;
            }


        }
        return B;

    }
}
```